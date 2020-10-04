
function time() {
    var time = new Date()
    var hrs = time.getHours()
    var min = time.getMinutes()

    if(hrs == 0){
        hrs = 12;
    }
    if(hrs < 10){
        hrs = '0' + hrs
    }
    if(min < 10){
        min = '0' + min
    }
    if(min == 0){
        min = '00'
    }

    document.getElementById('d01').innerHTML=hrs;
    document.getElementById('d02').innerHTML=min;
}
time();
setInterval(time,10000);