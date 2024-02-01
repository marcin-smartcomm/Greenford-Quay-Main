function InitializeSkyVariables()
{
    $('#returnBtn').on('click', () => {
        openSubpage("Home")
    })

    $.each($('.func-btn'), function () { 
        $(this).on('touchend', () => {
            AjaxGETCall("SkyCtrl", [roomCoreData.roomID, $(this).data('btn_name')])
        })
    });
}