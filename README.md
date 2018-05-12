# Esp8266---Nintendo-Labo-framework
With this framework, you can control the Nintendo Toy-Con House Input and perform action to esp8266


How It work ?

Each Input (Crank, Button or Kicker) will generate vibration in a script make with Nintendo Labo Garage.
The esp8266 is connected to a sw-420 vibration sensor module (GND to GND, VCC to 3V, DO to D5) and a counter will count the time that the vibration is detected and determine what to do .

Actually, this is the default values : 
1 - 2 seconds = Button
3 - 4 seconds = Crank
5 - 6 seconds = Kicker
