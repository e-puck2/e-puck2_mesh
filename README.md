# e-puck2_mesh
This project is based on the "mesh internal communication" example you can find in the ESP-IDF repository, that is adapted to work with the e-puck2 robot.
For more information refer to the [wiki](https://www.gctronic.com/doc/index.php?title=e-puck2_radio_module_development#Mesh_network)

The following section is the readme of the "mesh internal communication".

## Mesh Internal Communication Example

This example demonstrates how to use the mesh APIs to set up a mesh network, send and receive messages over the mesh network and etc.

Features Demonstrated

- mesh initialization

- mesh configuration

- mesh start

- mesh event handler

- root send and receive

- other nodes receive

Open project configuration menu (`idf.py menuconfig`) to configure the mesh network channel, router SSID, router password and mesh softAP settings.

When the mesh network is established and if you happen to run this example on ESP-WROVER-KIT boards, the RGB light indicator will show you on which layer devices are.
The pink reprents root; the yellow reprents layer 2; the red reprents layer 3; the blue reprents layer 4; the green reprents layer 5; the white reprents layer greater than 5.
Root continuously sends an On / Off control message to all devices in its routing table. Devices including root itself receive this message and do the On / Off.