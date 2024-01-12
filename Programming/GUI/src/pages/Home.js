let numOfCards = 0;

function InitializeHomeVariables()
{
    DrawAVCard()
    if(roomCoreData.tvCardRequired) DrawTVCard()
    UpdateSelectedSource()
}

function DrawAVCard()
{
    $.get("home-page-cards/AV-Card/AV-Card.html", (data) => { $('#mainCardsContainer').html(data) });

    $.get("home-page-cards/Card-Label.html", (data) => 
    { 
        $('#cardLabels').html(data) 
        $('#containerLabelX').html('AV')
        $('#containerLabelX').attr('id', `cardLabel${numOfCards}`);

        numOfCards++;
        PopulateAVCard()
    });
}
function PopulateAVCard()
{
    let templateBtn = ''
    $.get("home-page-cards/AV-Card/AV-Source.html", (data) => { 
        templateBtn = data
        
        $.each(roomCoreData.menuItems, function (i, source) { 
            $('#avCard').append(templateBtn)
            $('#srcBtnX').text(`${source.menuItemName}`)
            $('#srcBtnX').attr('id', `srcBtn${i}`)
        });

        ActivateSrcBtns()
    });
}
function ActivateSrcBtns()
{
    let pressDetection;
    if(panelType == "TSW") pressDetection = 'touchend'
    if(panelType == "iPad") pressDetection = 'click'
    else pressDetection = 'click'  

    $('*[id*=srcBtn]:visible').each(function() {
        $(this).on("click", function () {
            srcID = $(this).attr('id').replace("srcBtn", "")
            responseJSON = AjaxGETCall("ChangeSouceSelected", [roomCoreData.roomID, srcID])
            roomCoreData.sourceSelected = responseJSON.currentSource
            UpdateSelectedSource()
        });
    });
}
function UpdateSelectedSource()
{
    $('*[id*=srcBtn]:visible').each(function() {
        if($(this).text() === roomCoreData.sourceSelected)
            $(this).addClass("active-btn");
        else
            $(this).removeClass("active-btn");
    });

    UpdateVolumeControls()
}

function DrawTVCard()
{
    $.get("home-page-cards/TV-Card/TV-Card.html", (data) => { $('#mainCardsContainer').append(data) });

    $.get("home-page-cards/Card-Label.html", (data) => 
    { 
        $('#cardLabels').append(data) 
        $('#containerLabelX').html('TV')
        $('#containerLabelX').attr('id', `cardLabel${numOfCards}`);

        numOfCards++;
        ActivateTVBtns()
    });
}

function ActivateTVBtns()
{
    $('#TVOn').on('click', () => {
        AjaxGETCall("TVOnBtnPress", [roomCoreData.roomID])
    })
    $('#TVOff').on('click', () => {
        AjaxGETCall("TVOffBtnPress", [roomCoreData.roomID])
    })

    $('#TVVolUp').on('touchend', () => {
        console.log("Up");
        AjaxGETCall("VolUpBtnPress", [roomCoreData.roomID])
    })

    $('#TVVolDown').on('touchend', () => {
        console.log("Down");
        AjaxGETCall("VolDownBtnPress", [roomCoreData.roomID])
    })
}