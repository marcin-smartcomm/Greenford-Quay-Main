function InitializeFreeviewVariables()
{
    $('#returnBtn').on('click', () => {
        openSubpage("Home")
    })

    const BUTTONS_NUM = 100
    for(let i = 0; i < BUTTONS_NUM; i++)
    {
        if(document.getElementById(`srcBtn:${i}`) != null)
        {
            document.getElementById(`srcBtn:${i}`).addEventListener('touchend', function()
            {
                AjaxGETCall("FreeviewCtrl", [roomCoreData.roomID, i])
            })
        }
    }
}