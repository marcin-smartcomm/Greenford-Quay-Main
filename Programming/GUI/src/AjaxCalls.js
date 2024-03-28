function AjaxGETCall(endpoint, params)
{
    let dataToSend = ''

    if(params.length === 1) dataToSend = params[0];
    else if (params.length > 1)
    {
        $.each(params, function (i, value) { 
            if(i === params.length-1) dataToSend += value
            else dataToSend += value+':'
        });
    }

    return $.get(`http://${coreProcessorIP}:50000/api/${endpoint}?${dataToSend}`).responseJSON
}

function UnsubscribeFromCoreEvents()
{
    AjaxGETCall("Disconnect", [])
    adminEventStreamSource.close();
}

function SubscribeToCoreEvents()
{
    adminEventStreamSource = new EventSource(`http://${coreProcessorIP}:50001/api/events?${roomCoreData.roomID}`)

    adminEventStreamSource.onmessage = function(event) {
        console.log(event.data)
        CoreProcessorProcessIncomingEvent(event);
    }
    adminEventStreamSource.onopen = function(event) {
        console.log("Connected to Core Event Stream");
    }
    adminEventStreamSource.onerror = function(event) {
        console.log("connection error")
    }
}

function CoreProcessorProcessIncomingEvent(event)
{
    if(event.data.includes("Slider"))
    {
        let newVolLevel = event.data.split(':')[2];
        roomCoreData.volLevel = newVolLevel
        UpdateVolControls()
    }
    if(event.data.includes("Mute"))
    {
        let newMuteState = event.data.split(':')[2];
        roomCoreData.volMute = newMuteState
        UpdateMuteState()
    }
    if(event.data.includes("Locked"))
    {
        if(panelType == "TSW") DisplayLockedMessage(true);
    }
    if(event.data.includes("Unlocked"))
    {
        if(panelType == "TSW") RefreshPanelData();
    }
}