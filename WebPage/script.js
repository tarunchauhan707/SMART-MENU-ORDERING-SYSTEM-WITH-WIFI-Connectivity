
let OrderEle = document.getElementById('Order');
let WaiterEle = document.getElementById('Waiter');
let WaterEle = document.getElementById('Water');
  // Your web app's Firebase configuration
const firebaseConfig = {
        apiKey: "AIzaSyAzpKEiWDepXxMMYrMycCMwYx6BQGr_PYo",
        authDomain: "ismartmenu.firebaseapp.com",
        databaseURL: "https://ismartmenu-default-rtdb.firebaseio.com",
        projectId: "ismartmenu",
        storageBucket: "ismartmenu.appspot.com",
        messagingSenderId: "1070853129155",
        appId: "1:1070853129155:web:a8afeaa9a643ab64d1f376",
        URL: "https://ismartmenu-default-rtdb.firebaseio.com/"
};


// Initialize Firebase 
firebase.initializeApp(firebaseConfig);
var database = firebase.database();

// console.log(dataref1)
var dataref1 = database.ref('MENU/ORDER');
dataref1.on('value', function(snapshot) {
        const data = snapshot.val();
        OrderEle.innerText = data ? data : 'No data available';
        OrderEle.style.backgroundColor = "lightgrey";
});


var dataref2 = database.ref('MENU/WAITER');
dataref2.on('value', function(snapshot) {
        const data = snapshot.val();
        WaiterEle.innerText = data ? data : 'No data available';
        if(data != "NO CALLING WAITER"){
                WaiterEle.style.backgroundColor = "red";
        }else{
                WaiterEle.style.backgroundColor = "lightgrey";
        }
        
});


var dataref3 = database.ref('MENU/WATER');
dataref3.on('value', function(snapshot) {
        const data = snapshot.val();
        WaterEle.innerText = data ? data : 'No data available';
        if(data != "NO NEED WATER"){
                WaterEle.style.backgroundColor = "skyblue";
        }else{
                WaterEle.style.backgroundColor = "lightgrey";
        }
});