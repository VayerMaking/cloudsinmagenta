const { app, BrowserWindow } = require('electron')

let mainWindow;

function createWindow () {
  const win = new BrowserWindow({
    width: 800,
    height: 600,
    fullscreen: true,
    webPreferences: {
      nodeIntegration: true
    }
  })

  win.loadFile('smike.html')

  //win.webContents.openDevTools()
}

app.on("ready", ()=>{
  createWindow();
})

app.on('window-all-closed', () => {
  if (process.platform !== 'darwin') {
    app.quit()
  }
})

app.on('activate', () => {
  if (BrowserWindow.getAllWindows().length === 0) {
    createWindow()
  }
})
