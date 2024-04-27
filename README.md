# pams_main
Power Amp Monitoring System Mainboard Software

## About `pams`

### What is `pams`?

`pams` is an open source solution for implementing a health monitoring system for any generic power amplifier (PA).

Lots of industrial PAs feature some sort of health monitoring system to alert the user to the state of the PA. This project attempts to improve upon these by featuring a full color TFT touch screen, while also being as unobtrusive as possible, meaning that this system can be used in effectively *any* Power Amplifier.

### What is `pams_main`?

`pams_main` is the software component for the head unit for the monitoring system. The head unit features a touch TFT display to display the status of a power amplifier via an attached monitoring module.

We separate the actual monitoring from the display not only to improve performance of the individual systems, but to also increase the amount of available pins on a micro controller.


## Project Info
### Background
The `pams` project was conceived as a senior design project for my B.S. Electrical Engineering degree at the University of Kansas (EECS 502 Team 5).

This project started as a colaboration between the Center for Remote Sensing & Integrated Systems (CReSIS) and the EECS 502 senior design class. CReSIS makes their own Power Amplifiers in house, and while they perform just as well (if not better) as an industrial-grade PA, they lack the health-monitoring capabilities. As I was one of the few students who was both a researcher at CReSIS and a student in EECS 502, I was tasked by CReSIS to implement this as my senior design project.


### Credits

#### EECS 502 Team 5
- [Sebastian McMillan](https://github.com/snmcmillan) - Project Lead, Micro Controller Programming
- [Cordelia Lindsey]() - Project Lead, Systems Integration
- [Phil Leon]() - Power Distribution Design
- [Justin Becnel]() - RF Circuit Design

#### Special Thanks
- Fernando Rodriguez-Morales, Senior Scientist at CReSIS
- Jim McNaughton, Professor of the Practice at The University of Kansas

