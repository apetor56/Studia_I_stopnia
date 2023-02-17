const indices = new Array('d1', 'd2', 'd3', 'd3');

function myFunction(index) {
  indices.forEach(_index => {
    if(document.getElementById(_index).classList.contains("show") && index != _index) {
      document.getElementById(_index).classList.remove("show");
    }
  })
  document.getElementById(index).classList.toggle("show");
}

window.onclick = function(event) {
  if (!event.target.matches('.dropbtn')) {
    var dropdowns = document.getElementsByClassName("dropdown-content");
    var i;
    for (i = 0; i < dropdowns.length; i++) {
      var openDropdown = dropdowns[i];
      if (openDropdown.classList.contains('show')) {
        openDropdown.classList.remove('show');
      }
    }
  }
}
