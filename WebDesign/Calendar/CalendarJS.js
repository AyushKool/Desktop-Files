// JavaScript source code

var date =
{
    day: 0,
    month: 0,
    year: 0
};

var c, count;

var d, m;
var start, lm;
var today;

function setup() {
    d = select(".day");
    m = select(".month");
}

function draw() {
    date.day = day();
    date.month = month();
    date.year = year();
    today = new Date().toLocaleString('default', { weekday: 'long' });

    d.html(today);
    m.html(date.day + " " + monthName(date.month) + ", " + date.year);

    start = getWKNum(getOtherDayName(today, -date.day));

    lm = new Date(date.year, date.month - 1, 0).getDate();
    tm = new Date(date.year, date.month, 0).getDate();
    //console.log(lm + " " + date.month + " " + date.year);
    for (i = start - 1; i >= 0; i-- , lm--) {
        c = select('#0' + i);
        c.html(lm);
    }

    count = 1;
    for (i = start; i < 7; i++) {
        c = select('#0' + i);
        c.html(count++);
    }

    for (i = 1; i < 6; i++) {
        for (j = 0; j < 7; j++) {
            c = select('#' + i + j);
            if (count > tm)
                count = 1;
            c.html(count++);
        }
    }
}

//function getNumDayMon(mon) {
//    switch (mon) {
//        case 1:
//            return 31;
//        case 2:
//            return (new Date(date.year, 2, 0).getDate());
//        case 3:
//            return 31;
//        case 4:
//            return 30;
//        case 5:
//            return 31;
//        case 6:
//            return 30;
//        case 7:
//            return 31;
//        case 8:
//            return 31;
//        case 9:
//            return 30;
//        case 10:
//            return 31;
//        case 11:
//            return 30;
//        case 12:
//            return 31;
//    }
//}
function getOtherDayName(todayname, diff) {
    diff %= 7;
    var sum = getWKNum(todayname) + diff + 1;
    if (sum < 0)
        sum += 7;
    return getWKName(sum);
}

function getWKNum(name) {
    if (name == 'Monday')
        return 0;
    else if (name == 'Tuesday')
        return 1;
    else if (name == 'Wednesday')
        return 2;
    else if (name == 'Thursday')
        return 3;
    else if (name == 'Friday')
        return 4;
    else if (name == 'Saturday')
        return 5;
    else if (name == 'Sunday')
        return 6;

}

function getWKName(num) {
    if (num == 0)
        return 'Monday';
    else if (num == 1)
        return 'Tuesday';
    else if (num == 2)
        return 'Wednesday';
    else if (num == 3)
        return 'Thursday';
    else if (num == 4)
        return 'Friday';
    else if (num == 5)
        return 'Saturday';
    else if (num == 6)
        return 'Sunday';

}



function monthName(mon) {
    switch (mon) {
        case 1:
            return "January";
        case 2:
            return "Febuary";
        case 3:
            return "March";
        case 4:
            return "April";
        case 5:
            return "May";
        case 6:
            return "June";
        case 7:
            return "July";
        case 8:
            return "August";
        case 9:
            return "September";
        case 10:
            return "October";
        case 11:
            return "November";
        case 12:
            return "December";
    }
}