let coreProcessorIP = ''
let panelType = ''
let roomCoreData = ''
let interval;

window.onload = function(){
    $.ajaxSetup({async: false, timeout: 2000});
    LoadCoreData()
    SubscribeToCoreEvents()
    ActivatePowerBtn()
    inactivityTime()

    if (panelType == "TSW") openSubpage("ScreenSaver")
    if (panelType == "iPad") openSubpage("AreaSelect")
    interval = window.setInterval(UpdateTime, 1000)
}

let inactivityTime = function() {
    let time;
    document.addEventListener('touchstart', () => { resetTimer(); })
    function logout() { openSubpage("ScreenSaver"); }
    function resetTimer() {
      clearTimeout(time);
      time = setTimeout(logout, 60000)
    }
};

function UpdateTime()
{
    var date = new Date();
    var n = date.toDateString();
    var time = date.toLocaleTimeString();

    document.getElementById("TODContainer").innerHTML = n + "\n" + time;
}

function LoadCoreData()
{
    $.getJSON("CoreData.json",  function(data){
        coreProcessorIP = data.coreProcessorIP
        panelType = data.panelType
        roomCoreData = AjaxGETCall('RoomData', [999])

        if(panelType == "TSW") $('#roomNameContainer').text(roomCoreData.roomName)

        if(panelType == "iPad") 
        {
            $('#roomNameContainer').html(roomCoreData.roomName)
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