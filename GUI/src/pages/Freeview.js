function InitializeFreeviewVariables()
{
    document.getElementById("returnBtn").addEventListener('click', function() {
        openSubpage("Home")
    })

    const BUTTONS_NUM = 100
    for(let i = 0; i < BUTTONS_NUM; i++)
    {
        if(document.getElementById(`srcBtn:${i}`) != null)
        {
            document.getElementById(`srcBtn:${i}`).addEventListener('touchend', function()
            {
                sendMessage(`srcBtn:${i}:Freeview`)
            })
        }
    }
    document.getElementById(`volUpBtn`).addEventListener('touchend', function()
    {
        sendMessage(`VolumeUp`)
    })
    document.getElementById(`volDownBtn`).addEventListener('touchend', function()
    {
        sendMessage(`VolumeDown`)
    })
}