let coreProcessorIP = ''
let panelType = ''
let roomCoreData = ''
let currentTimeInterval;
let loggedOut = true;

window.onload = function(){
    $.ajaxSetup({async: false, timeout: 2000});
    LoadCoreData()
    ActivatePowerBtn()
    inactivityTime()

    if (panelType == "TSW") 
    {
        if(roomCoreData.tpLocked) DisplayLockedMessage(true)
        else openSubpage("ScreenSaver"); 
    }
    if (panelType == "iPad") openSubpage("AreaSelect")
}

function RefreshPanelData()
{
    LoadCoreData()
    if (panelType == "TSW") 
    {
        if(roomCoreData.tpLocked) DisplayLockedMessage(true)
        else openSubpage("ScreenSaver"); 
    }
}

let inactivityTime = function() {
    let time;
    document.addEventListener('touchstart', () => {
        if(panelType == "TSW")
        {
            if(roomCoreData.tpLocked || loggedOut) 
            {
                RefreshPanelData();
                if(loggedOut) 
                {
                    SubscribeToCoreEvents()
                    currentTimeInterval = window.setInterval(UpdateTime, 1000)
                }
                loggedOut = false;
            }
        }
        if(panelType == "iPad")
        {        
            if(loggedOut)
            {
                LoadCoreData()
                SubscribeToCoreEvents()
                currentTimeInterval = window.setInterval(UpdateTime, 1000)
                loggedOut = false;
            }
        }

        resetTimer(); 
    })
    function logout() { 
        loggedOut = true;
        clearInterval(currentTimeInterval)
        UnsubscribeFromCoreEvents()

        if(panelType == "TSW")
        {
            if(roomCoreData.tpLocked) DisplayLockedMessage(true)
            else openSubpage("ScreenSaver"); 
        }
        else openSubpage("ScreenSaver"); 
    }
    function resetTimer() {
      clearTimeout(time);
      time = setTimeout(logout, 60000)
    }
};

function LoadCoreData()
{
    $.getJSON("CoreData.json",  function(data){
        coreProcessorIP = data.coreProcessorIP
        panelType = data.panelType
        roomCoreData = AjaxGETCall('RoomData', [999])

        FillRoomName()
        if(panelType == "iPad") 
        {
            $.get("components/room-select-btn/room-select-btn.html", (data) => { $('#roomNameContainer').append(data) });
            $('#areaSelectBtn').on('click', () => {
                openSubpage("AreaSelect")
            })
        }

        UpdateVolumeControls()
    }).fail(function(){
        console.log("An error has occurred.");
    });
}

function FillRoomName()
{
    let leftArrow, rightArrow;
    $.get("components/room-select-left-arrow/room-select-left-arrow.html", (data) => { leftArrow = data });
    $.get("components/room-select-right-arrow/room-select-right-arrow.html", (data) => { rightArrow = data });

    if(roomCoreData.leftNeighbour != -1 && roomCoreData.rightNeighbour != -1)
        $('#roomNameContainer').html(`${leftArrow} ${roomCoreData.roomName} ${rightArrow}`)

    else if (roomCoreData.leftNeighbour != -1 && roomCoreData.rightNeighbour == -1)
        $('#roomNameContainer').html(`${leftArrow} ${roomCoreData.roomName} <i id="arrow-place-holder"></i>`)

    else if (roomCoreData.leftNeighbour == -1 && roomCoreData.rightNeighbour != -1)
        $('#roomNameContainer').html(`<i id="arrow-place-holder"></i> ${roomCoreData.roomName} ${rightArrow}`)

    else if (roomCoreData.leftNeighbour == -1 && roomCoreData.rightNeighbour == -1)
        $('#roomNameContainer').html(`${roomCoreData.roomName}`)

    ActivateRoomChangeArrows()
}

function ActivateRoomChangeArrows()
{
    let rightArrow = $('#rightArrowRoomSelect')
    if(rightArrow.length > 0) 
        rightArrow.on("touchstart", () => {
            responseJSON = AjaxGETCall("ChangeZone", [roomCoreData.rightNeighbour])
            location.reload()
        })

    let leftArrow = $('#leftArrowRoomSelect')
    if(leftArrow.length > 0) 
        leftArrow.on("touchstart", () => {
            responseJSON = AjaxGETCall("ChangeZone", [roomCoreData.leftNeighbour])
            location.reload()
        })
}

function UpdateVolumeControls()
{
    $('#volControlsContainer').html("")

    if(roomCoreData.sourceSelected != "Off")
    {
        $.each(roomCoreData.menuItems, function (i, value) { 
             if(value.menuItemName === roomCoreData.sourceSelected)
             {
                if(value.volControlType === "Slider") DrawSliderVolControl()
                if(value.volControlType === "Btns") DrawBtnsVolControlType()
             }
        });
    }

    VolumeControlsAnimation()
}

function VolumeControlsAnimation()
{
    $('.vol-controls-container').addClass('vol-controls-fly-in')
    setTimeout(() => {
        $('.vol-controls-container').removeClass('vol-controls-fly-in')
    }, 500);
}

function DrawSliderVolControl()
{
    volSliderComponent = $.get("components/vol-slider/vol-slider.html").responseText
    $('#volControlsContainer').append(volSliderComponent)

    ActivateMuteBtn()
    ActivateSliderVolControls()
}

function DrawBtnsVolControlType()
{
    volBtnsComponent = $.get("components/vol-btns/vol-btns.html").responseText
    $('#volControlsContainer').append(volBtnsComponent)

    ActivateMuteBtn()
    ActivateBtnsVolControl()
}

function ActivateMuteBtn()
{
    $('#volMute').on("click", () => {
        AjaxGETCall("MuteVolume", [roomCoreData.roomID])
    })
}

function ActivateSliderVolControls()
{
    $('#volSlider').on('input', (a) => {
        AjaxGETCall("ChangeVolumeLevel", [roomCoreData.roomID, $('#volSlider').val()])
    })
    UpdateVolControls()
    UpdateMuteState()
}

function UpdateVolControls()
{
    $('#volSlider').attr("value", `${roomCoreData.volLevel}`)
    $('#volLabel').text(`${roomCoreData.volLevel}%`)
}

function UpdateMuteState()
{
    if(roomCoreData.volMute == 'true' || roomCoreData.volMute) 
    {
        $('#volMuteIcon').removeClass('fa-volume-high');
        $('#volMuteIcon').addClass('fa-volume-xmark');
    }
    if(roomCoreData.volMute == 'false' || !roomCoreData.volMute) 
    {
        $('#volMuteIcon').removeClass('fa-volume-xmark');
        $('#volMuteIcon').addClass('fa-volume-high');
    }
}

function ActivateBtnsVolControl()
{
    $('#volUp').on('click', () => {
        AjaxGETCall("VolUpBtnPress", [roomCoreData.roomID])
    })
    $('#volDown').on('click', () => {
        AjaxGETCall("VolDownBtnPress", [roomCoreData.roomID])
    })
}

function ActivatePowerBtn()
{
    $('#pwrBtn').on('click', ()=> {
        TogglePopUp("PowerOff")
    })
}