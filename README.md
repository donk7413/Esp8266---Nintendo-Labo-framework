# Esp8266---Nintendo-Labo-framework
With this framework, you can control the Nintendo Toy-Con House Input and perform action to esp8266


How It work ?

Each Input (Crank, Button or Kicker) will generate vibration in a script make with Nintendo Labo Garage.

The esp8266 is connected to a sw-420 vibration sensor module (GND to GND, VCC to 3V, DO to D5) and a counter will count the time that the vibration is detected and determine what to do . Actually each action can send a HTTP request (to connect to another 

Wiring Schema :



![alt text](https://image.noelshack.com/fichiers/2018/20/2/1526378386-esp-sw.png)

And this is the Nintendo Labo Garage Script :




I have set the vibration value in the output setting of the vibration module.

It's very easy :
Everytime that the user use a part, the left Joy-Con will emit a vibration for X seconds. That's all for the Labo Garage parts.

Actually, this is the default values : 
1 - 2 seconds = Button
3 - 4 seconds = Crank
5 - 6 seconds = Kicker

The result : 
![alt text](https://media.giphy.com/media/1itJgjw6rr7YflfdTF/giphy.gif)
