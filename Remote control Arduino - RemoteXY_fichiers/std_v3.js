
function getXmlHttp() {
  var xmlhttp;
  try {
    xmlhttp = new ActiveXObject("Msxml2.XMLHTTP");
  } catch (e) {
    try {
      xmlhttp = new ActiveXObject("Microsoft.XMLHTTP");
    } catch (E) {
      xmlhttp = false;
    }
  }
  if (!xmlhttp && typeof XMLHttpRequest!='undefined') {
    xmlhttp = new XMLHttpRequest();
  }
  return xmlhttp;
}


function getElementPosition(elem)
{
   var w = elem.offsetWidth;
   var h = elem.offsetHeight;
   var l = 0;
   var t = 0;
   while (elem) {
     l += elem.offsetLeft;
     t += elem.offsetTop;
     elem = elem.offsetParent;
   }
   return {"left":l, "top":t, "width": w, "height":h};
}

function Windows_SetOpacity (el, opacity)
{
  var opacityfield;
  if (el==null) return;
  if (typeof document.body.style.opacity == 'string') opacityfield = 'opacity';
  else if (typeof document.body.style.MozOpacity == 'string') opacityfield =  'MozOpacity';
  else if (typeof document.body.style.KhtmlOpacity == 'string') opacityfield =  'KhtmlOpacity';
  else if (document.body.filters && navigator.appVersion.match(/MSIE ([\d.]+);/)[1]>=5.5) opacityfield =  'filter';

  if (opacityfield=='opacity') {el.style.opacity = opacity;}
  else if (opacityfield=='MozOpacity') {el.style.MozOpacity = opacity;}
  else if (opacityfield=='KhtmlOpacity') {el.style.KhtmlOpacity = opacity;}
  else if (opacityfield=='filter') {el.filters.alpha.opacity = Math.round (opacity*100);} 
}

function isSmall () {
  return matchMedia("(max-width: 319px)").matches;
}

function isMobile () {
  return matchMedia("(max-width: 767px)").matches;
}

function isTablet () {
  return matchMedia("(max-width: 979px)").matches;
}

var contentOopacity = 1;
var contentInterval;

function Windows_HideContent ()
{
  var newContentOopacity = 0.2;
  mf = document.getElementById("content");
  clearInterval (contentInterval);
  if (contentOopacity > newContentOopacity) {
    contentInterval = setInterval (function() { 
      if (newContentOopacity >= contentOopacity) {
        clearTimeout (contentInterval);
      }
      else {
        contentOopacity=contentOopacity-0.101;
        if (contentOopacity<newContentOopacity) contentOopacity=newContentOopacity;
        Windows_SetOpacity (mf, contentOopacity);
      } 
    }, 25);
  } 
}

function Windows_ShowContent ()
{
  var newContentOopacity = 1;
  mf = document.getElementById("content");
  clearInterval (contentInterval);
  if (contentOopacity < newContentOopacity) {
    contentInterval = setInterval (function() { 
      if (newContentOopacity <= contentOopacity) {
        clearTimeout (contentInterval);
      }
      else {
        contentOopacity=contentOopacity+0.101;
        if (contentOopacity>newContentOopacity) contentOopacity=newContentOopacity;
        Windows_SetOpacity (mf, contentOopacity);
      } 
    }, 25);
  } 
}



var openedWindow = null;

function Windows_Open (id) {
  Actions_Close ();
  Windows_Close ();
  var pl = document.getElementById('windows');
  var win = document.getElementById(id);
  if (win && pl) {
    pl.style.display = 'table'; 
    win.style.display = 'block';
    pl.onmousedown=null;
    Windows_HideContent ();      
    openedWindow = id;
    return win; 
  }
}

// pos = 0 - left
// pos = 1 - right
function Windows_OpenAsMenu (id, pos) {
  if (pos===undefined) pos=0; 
  Windows_Close ();
  var win = document.getElementById(id);
  if (win) {
    var position = 70;
    if (pos==0) {
      win.style.left = "-"+position+"%";
      Windows_Open (id);
      var interval = setInterval (function() { 
          if (position <= 0) {
            clearTimeout (interval);
          }
          position=position-10;
          win.style.left = "-"+position+"%";
        }, 25);
    }
    if (pos==1) {
      win.style.right = "-"+position+"%";
      Windows_Open (id);
      var interval = setInterval (function() { 
          if (position <= 0) {
            clearTimeout (interval);
          }
          position=position-10;
          win.style.right = "-"+position+"%";
        }, 25);    
    }
  }
}

function Windows_Close ()
{
  if (openedWindow != null) {
    var pl = document.getElementById('windows');
    var win = document.getElementById(openedWindow);
    if (win && pl) {
      pl.style.display = 'none';
      win.style.display = 'none';
      Windows_ShowContent ();
      pl.onclick=null;
    }
    openedWindow = null;
  }
}

var openedAction = null;

function Actions_Open (id, x, y, align)
{
  Actions_Close ();
  var pl = document.getElementById('actions');
  var win = document.getElementById(id);
  if (win && pl) {
    pl.style.display = 'block'; 
    win.style.position="absolute";
    win.style.left = x +'px';
    win.style.top = y +'px';
    win.style.display = 'block';
    if (align==1) {
      win.style.left = (x-win.clientWidth-1)+'px';
    }
    openedAction = id;
      pl.onclick=function (e) {
          Actions_Close ();
      } 

  }
}

function Actions_Close () {
  if (openedAction != null) {
    var pl = document.getElementById('actions');
    var win = document.getElementById(openedAction);
    if (win && pl) {
      pl.style.display = 'none'; 
      win.style.display = 'none'; 
      pl.onclick = ""
    }  
    openedAction = null;
  }
}


function Windows_AddContextMenuElement (contextmenu, name, onclick, active) 
{
  html = contextmenu.innerHTML;
  if (active) {
    html += '<div><a href="#" onclick="'+onclick+'">'+name+'</a></div>';
  }
  else {
    html += '<div><p>'+name+'</p></div>';  
  }
  contextmenu.innerHTML = html;
}

function Windows_AddContextMenuDivider (contextmenu) 
{
  html = contextmenu.innerHTML;
  html += '<div style="padding-top: 3px; width:100%;"></div><div style="padding-top: 3px; width:100%; border-top: 1px solid #c0c0c0;"></div>';
  contextmenu.innerHTML = html;
}





function fixCodeTag () {
  if (isMobile ()) {
    var els = document.getElementsByClassName ('cppcode');
    for (var i in els) {
      for (var j in els[i].childNodes) {
        els[i].style.height = (els[i].childNodes[j].clientHeight+26)+'px';
      }
    }
  }
}

