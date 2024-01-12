function InitializePowerOffVariables()
{
    document.getElementById("pwrOffConfirm").addEventListener('click', function()
    {
        responseJSON = AjaxGETCall("RoomShutdown", [roomCoreData.roomID])
        roomCoreData.sourceSelected = responseJSON.currentSource
        UpdateSelectedSource()
        
        openSubpage("ScreenSaver")
        TogglePopUp("PowerOff")
        $('#volControlsContainer').html("")
    })
    document.getElementById("pwrOffCancel").addEventListener('click', function()
    {
        TogglePopUp("PowerOff")
    })
}