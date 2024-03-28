function InitializeAreaSelectVariables()
{
    responseJSON = AjaxGETCall("RoomsList", [])
    UpdateAvailableZones(responseJSON)
    $('#homeBtn').on('click', () => {
        openSubpage("Home")
    })
    $('#lockUnlockBtn').on('click', () => {
        openSubpage("LockUnlock")
    })
}

function UpdateAvailableZones(zoneNames)
{
    zoneNames.forEach(name => {
        $.get("components/room-btn/room-btn.html", (data) => { 
            $('#roomBtnsContainer').append(data) 

            $('#X').text(name.split(':')[0])
            $('#X').attr('id', `zoneBtn${name.split(':')[1]}`)
        });
    });

    ActivateZoneBtns()
}

function ActivateZoneBtns()
{
    $('*[id*=zoneBtn]:visible').each(function() {
        $(this).on("click", function () {
            zoneID = $(this).attr('id').replace("zoneBtn", "")
            responseJSON = AjaxGETCall("ChangeZone", [zoneID])
            location.reload()
        });

        if($(this).html() == roomCoreData.roomName) $(this).addClass('active-btn')    
    });
}