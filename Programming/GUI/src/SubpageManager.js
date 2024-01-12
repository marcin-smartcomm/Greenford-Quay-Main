let backBtn;
let previousSubpage;
let currentSubpage;
let blankOutBtnsVis = false;
var popupOpen = false;

function openSubpage(file)
{
  document.getElementById("subpageSection").classList.add("transitionIn")
  
  if(currentSubpage != null)
    previousSubpage = currentSubpage;
  else
    previousSubpage = "ScreenSaver";

  currentSubpage = file;

  var rawFile = new XMLHttpRequest();
  rawFile.open("GET", './pages/'+file+'.html', false);
  rawFile.onreadystatechange = function ()
  {
      if(rawFile.readyState === 4)
      {
          if(rawFile.status === 200 || rawFile.status == 0)
          {
              var allText = rawFile.responseText;
              document.querySelector('#subpageSection').innerHTML = allText;
          }
      }
  }
  rawFile.send(null);
  rawFile.DONE;
  
  InitializeSubpageVariables(file);

  setTimeout(ClearTransition, 500);
}

function TogglePopUp(file)
{
  popupOpen = !popupOpen;

  if(popupOpen)
  {
    var rawFile = new XMLHttpRequest();
    rawFile.open("GET", './popups/'+file+'.html', false);
    rawFile.onreadystatechange = function ()
    {
        if(rawFile.readyState === 4)
        {
            if(rawFile.status === 200 || rawFile.status == 0)
            {
              var allText = rawFile.responseText;
              var popup = document.createElement("div")
              popup.setAttribute("id", "popupSection")
              popup.innerHTML = allText;
              document.querySelector('#subpageSection').appendChild(popup);
            }
        }
    }
    rawFile.send(null);
    rawFile.DONE;
  
    InitializeSubpageVariables(file);
  }
  else if (document.getElementById('popupSection') != null)
    document.getElementById('popupSection').remove()

}

function ClearTransition()
{
  document.getElementById("subpageSection").classList.remove("transitionIn");
}

function InitializeSubpageVariables(pageToInitialize)
{
  if(pageToInitialize == "ScreenSaver") InitializeScreenSaverVariables()
  if(pageToInitialize == "PowerOff") InitializePowerOffVariables()
  if(pageToInitialize == "Home") InitializeHomeVariables()
  if(pageToInitialize == "Sky") InitializeSkyVariables()
  if(pageToInitialize == "Freeview") InitializeFreeviewVariables()
  if(pageToInitialize == "AreaSelect") InitializeAreaSelectVariables()
}