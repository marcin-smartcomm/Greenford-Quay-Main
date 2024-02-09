function InitializeFreeviewVariables()
{
    $('#returnBtn').on('click', () => {
        openSubpage("Home")
    })

    $.each($('.func-btn'), function () { 
        $(this).on('touchend', () => {
            AjaxGETCall("FreeviewCtrl", [roomCoreData.roomID, $(this).data('btn_name')])
        })
    });
}