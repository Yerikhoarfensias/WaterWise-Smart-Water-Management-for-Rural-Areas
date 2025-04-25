
// Simulated water level update
let level = 70;
setInterval(() => {
  level = Math.floor(Math.random() * 100);
  document.getElementById('water-bar').style.height = level + '%';
  document.getElementById('water-level').textContent = level + '%';
}, 5000);
