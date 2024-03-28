function InitializeLockUnlockVariables()
{
  UpdateLockStates()
  ActivateLockBtns()
  //ActivateUnlockBtns()

  $('#returnBtn').on('click', () => {
      openSubpage("AreaSelect")
  })
}

function UpdateLockStates()
{    
  data = AjaxGETCall("LockUnlockStates", [])
  data.forEach(report => {
    if(report.tpLocked)
    {
      if(document.getElementById(`disable${report.roomID}`) != null)
      {
        $(`#disable${report.roomID}`).addClass("active-btn")
        $(`#enable${report.roomID}`).removeClass("active-btn")
      }
    }
    else
    {
      if(document.getElementById(`enable${report.roomID}`) != null)
      {
        $(`#disable${report.roomID}`).removeClass("active-btn")
        $(`#enable${report.roomID}`).addClass("active-btn")
      }
    }
  });
}

function ActivateLockBtns()
{
  $('*[id*=disable]').each(function(){
    $(this).on('click', function(){
      let roomID = $(this).attr('id').replace("disable", "")
      responseJSON = AjaxGETCall(`LockTP`, [roomID])
      if(responseJSON.success == "true") UpdateLockStates()
    })
  })

  $('*[id*=enable]').each(function(){
    $(this).on('click', function(){
      let roomID = $(this).attr('id').replace("enable", "")
      responseJSON = AjaxGETCall(`UnlockTP`, [roomID])
      if(responseJSON.success == "true") UpdateLockStates()
    })
  })
}