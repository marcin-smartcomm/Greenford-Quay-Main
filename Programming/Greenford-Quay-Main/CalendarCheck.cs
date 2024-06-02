using Google.Apis.Calendar.v3;
using Google.Apis.Services;
using System;
using System.Timers;
using System.Threading.Tasks;

namespace Greenford_Quay_Main
{
    public class CalendarCheck
    {
        string _calendarName = string.Empty;
        string _apiKey = string.Empty;
        string _calendarId = string.Empty;

        public event Action<bool> inMeeting;

        public CalendarCheck(string calendarId, string apiKey, string calendarName)
        {
            _calendarId = calendarId;
            _apiKey = apiKey;
            _calendarName = calendarName;

            var timer = new Timer();
            timer.Interval = 60000;
            timer.Elapsed += Timer_Elapsed;
            timer.Start();
        }

        Task _check;
        private void Timer_Elapsed(object sender, ElapsedEventArgs e)
        {
            if (_check != null) _check.Dispose();

            _check = Task.Run(() =>
            {
                try { GetResponse(_calendarId); }
                catch (Exception ex) { ConsoleLogger.WriteLine("Problem Fetching Calendar Info: " + ex); }
            });
        }

        CalendarService _service;
        EventsResource.ListRequest _request;
        Google.Apis.Calendar.v3.Data.Events _responseData;
        void GetResponse(string calendarId)
        {
            try
            {
                DateTime today = DateTime.Today;

                using (_service = new CalendarService(new BaseClientService.Initializer()
                {
                    ApiKey = _apiKey,
                    ApplicationName = "Api key example"
                })
                )
                {
                    _request = _service.Events.List(calendarId);
                    _request.Fields = "items(summary,start,end)";
                    _request.OrderBy = EventsResource.ListRequest.OrderByEnum.Updated;
                    _request.UpdatedMinDateTimeOffset = today;
                    _responseData = _request.Execute();

                    ProcessResponse(_responseData);
                }
            }
            catch (Exception ex) 
            { 
                ConsoleLogger.WriteLine("Problem Fetching Calendar Info 2: " + ex);
            }
        }

        void ProcessResponse(Google.Apis.Calendar.v3.Data.Events response)
        {
            bool inMeetingState = false;

            foreach (var item in response.Items)
            {
                DateTimeOffset createdTime = item.Start.DateTimeDateTimeOffset.Value;

                if (createdTime.Day == DateTime.Now.Day && createdTime.Month == DateTime.Now.Month && createdTime.Year == DateTime.Now.Year)
                {
                    DateTimeOffset startTime = item.Start.DateTimeDateTimeOffset.Value;
                    DateTimeOffset endTime = item.End.DateTimeDateTimeOffset.Value;

                    int startMinutesFromMidnight = startTime.Hour * 60 + startTime.Minute;
                    int endMinutesFromMidnight = endTime.Hour * 60 + endTime.Minute;
                    int timeNowMinutesFromMidnight = DateTime.Now.Hour * 60 + DateTime.Now.Minute;

                    if (timeNowMinutesFromMidnight >= startMinutesFromMidnight && timeNowMinutesFromMidnight < endMinutesFromMidnight)
                    {
                        ConsoleLogger.WriteLine($"{_calendarName}: {item.Summary} - In this meeting");
                        inMeetingState = true;
                    }
                    else
                        ConsoleLogger.WriteLine($"{_calendarName}: {item.Summary} - Not in this meeting");
                }
            }

            if (inMeeting != null) inMeeting(inMeetingState);
        }
    }
}
