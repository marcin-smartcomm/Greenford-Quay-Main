function InitializeScreenSaverVariables()
{
    document.getElementById("screenSaverImg").addEventListener('click', function() {
        openSubpage("Home")

        responseJSON = AjaxGETCall("GetSouceSelected", [roomCoreData.roomID])
        roomCoreData.sourceSelected = responseJSON.currentSource
        UpdateSelectedSource()
    })
}