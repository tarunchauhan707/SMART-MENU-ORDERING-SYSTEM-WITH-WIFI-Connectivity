# SMART-MENU-ORDERING-SYSTEM-WITH-WIFI-CONNECTIVITY (DishDash)
***              
### ABSTRACT
***
The major issue faced in restaurants and hotels is the quality of service
provided by them especially ordering of food. Traditionally, it used to take a
long time for food ordering as waiter used to note down orders, place it kitchen
and the food was prepared. It also involved traditional pen and paper method
and the process was time consuming. It also involved a lot of wastage of paper.
Hence, we have designed the smart restaurant in which the orders will be
placed paperless using Arduino UNO, TFT touch display connected to the
kitchen chef directly using ESP WIFI connectivity. This acted as the transmitting
side. At the receiving side, the order placed is seen on Monitor/Screen through
web server. Hence, the workers focused on billing and other work process and
provided better quality services. We found out that this method is useful in
many ways like- It not only saved the wastage of paper but also reduced the
burden on the waiters and workers to great extent. Time management was also
done as more and more customers could be handled by taking their orders and
provide quality service. This setup is quite practical on basis such that this
system can be implemented for small startups hotels and restaurants. The
investment cost is also one-time investment as it requires less maintenance.
The only fact it requires is to update the system as per our convenience and
new offers. It also required average skilled labor to operate.Its grasping factor is
that the waiters can involve them in the processes of billing and other
processes. Hence it promotes the multi-tasking process and the system helps in
better customer end services.
***
### INTRODUCTION
***
The smart restaurant in which the orders will be placed paperless
using Arduino UNO, TFT touch display connected to the kitchen chef
directly using ESP WIFI connectivity. This acted as the transmitting
side. At the receiving side, the order placed is seen on
Monitor/Screen through web server. Hence, the workers focused on
billing and other work process and provided better quality services.
We found out that this method is useful in many ways like- It not only
saved the wastage of paper but also reduced the burden on the
waiters and workers to great extent.

![smartmenu](https://github.com/tarunchauhan707/SMART-MENU-ORDERING-SYSTEM-WITH-WIFI-Connectivity/assets/129646051/5f5dd3ed-22be-4a4d-bfa2-5b620f36ea0f)


***

### PROBLEM STATEMENT
***
1. To use the traditional food ordering system is entirely a
manual process which involves waiters, pen and paper.
2. To make customer wait for waiters to take the order in
pen and paper system.
3. To use traditional system is simple; but it involves errors
while noting down the orders as well as in making calcu-
lations.
***

### WORKING AND METHODOLOGY
***
Our Smart restaurant menu ordering system is basically di-
vided into two parts : Transmitter section (Customer Side) and
Receiver Section.Whenever the customer will enter the hotel
and take a table, he will read the menu given on TFT display
which will be mounted on table. hen after making suitable
decision the customer will place the order using TFT display
with the help of touch-screen or touch-stick system. The order
will be processed by the Arduino UNO and the data will be
sent serially to the esp8266 which will sent the to server of
the Restaurant.Through the Server,Chef in Kitchen side will
access the food orders data. In this way, the food will be pre-
pared at the faster rate and time will be saved and more orders
can be taken. The prepared food will be taken directly to the
customer from kitchen. Hence, also called as interaction cum
service.
1.<u> Serial Communication</u>
Serial communication between an Arduino Uno and an
ESP8266 allows for data exchange between the two devices.
Setup for Communication: Connect the TX pin of the Ar-
duino to the RX pin of the ESP8266. Connect the RX pin of
the Arduino to the TX pin of the ESP8266. Software Config-
uration: Baud Rate: Set the same baud rate on both devices
for consistent communication
2.<u>Transmitter side and Reciever Side</u>
Smart restaurant menu ordering system is basically divided
into two parts : Transmitter section (Customer Side)
and Receiver Section.
2.1. Transmitter Side

Figure 4. Serial communication between esp8266 and arduino uno
Figure 5. Transmitter Side(customer side)
2.2. Reciever Side
Web Interface Development: Create a user-friendly web
page using HTML, CSS, and Javascript. This page will display
the orders at the Reciever Side.
Firebase Integration: Set up a Firebase project and Real-
time Database. Web Server: The web server will continuously
listen to the Firebase database for updates. When a new order
is placed, the web page will be updated to reflect the latest
order status.

***

### Advantages
1. No need of a person to take order from the table.
2. Dynamic Menu Updates.  
3. Contactless Ordering.
4. Integration with IoT Devices.  
5. Easy to install because of wireless interface.   
6. Usage of tft touchscreen display in performing the task.
***

### Future Scope
1. Integration with restaurant management software for real-time
inventory tracking and order processing.
2. Mobile app development for remote ordering and table
reservation.




