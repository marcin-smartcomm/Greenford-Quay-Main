using Google.Apis.Calendar.v3;
using Google.Apis.Services;
using System;
using System.Timers;
using System.Threading.Tasks;

namespace Greenford_Quay_Main
{
    public class CalendarCheck
    {
        ControlSystem _cs;

        string _calendarName = string.Empty;
        string _apiKey = string.Empty;
        string _calendarId = string.Empty;

        public event Action<bool> inMeeting;

        public CalendarCheck(ControlSystem cs, string calendarId, string apiKey, string calendarName)
        {
            _cs = cs;
            _calendarId = calendarId;
            _apiKey = apiKey;
            _calendarName = calendarName;

            var timer = new Timer();
            timer.Interval = 5000;
            timer.Elapsed += Timer_Elapsed;
            timer.Start();
        }

        Google.Apis.Calendar.v3.Data.Events responseData = null;
        private void Timer_Elapsed(object sender, ElapsedEventArgs e)
        {
            Task.Run(() =>
            {
                GetResponse(_calendarId);
            });
        }

        async void GetResponse(string calendarId)
        {
            DateTime today = DateTime.Today;
            var service = new CalendarService(new BaseClientService.Initializer()
            {
                ApiKey = _apiKey,
                ApplicationName = "Api key example"
            });

            var request = service.Events.List(calendarId);
            request.Fields = "items(summary,start,end)";
            request.OrderBy = EventsResource.ListRequest.OrderByEnum.Updated;
            request.UpdatedMinDateTimeOffset = today;
            responseData = await request.ExecuteAsync();

            ProcessResponse(responseData);
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
