
# MQTT protocol Basics

This protocol invented in 1999   
MQTT stands for Message Queuing Telemetry Transport  
Example: youtube   
this protocol is publisher subscriber base protocol    
## 2 main things in this protocol    
-Topic: topic is the from of addresing that allows to mqtt client to share data. topic explian the structure if data     
- massage or payload: this the data or massage which publish or subscribe client    

### Two main part of mqtt protocol 

1. client: client means user of mqtt protocol this is either this can be publisher or it can be subscriber       
- Publisher: Publisher publish the massage or data on the mqtt broker. ex. sensors.     
- subscriber: subsriber subscribe the massage or data for accessing this data and use it. ex. laptops.
2. MQTT Broker: mqtt broker is the heart of the mqtt protocol mqtt broker is the server we can able to publish our massage on it or subscribe the any massage from it.       


#### We have one library for mqtt protocol "pubsubclient" we can use this library    
in this library function avilable to connect, disconnect, publish, subcribe, this kind of opretions 


