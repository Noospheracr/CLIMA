# CLIMA
## PROJECT RATIONALE
The unpredictability and profound impact of climate on every facet of life, including business and consumer behavior, is a matter of increasing urgency and importance. Far from a novelty, understanding and integrating climate data into business strategies is becoming a necessity for resilience and adaptability in a rapidly changing world.
The implications of climate are vast, affecting supply chains, determining market availability, influencing consumer needs and behaviors, and even dictating the economic viability of certain business models. Some interesting facts, & newly developed services supporting this theses (see Further References on the right): 
- Weather significantly affects consumer behavior, influencing mood, purchase decisions, and spending levels. It is the second largest influence on consumer behavior after economic conditions​​. [WeatherAds] 
- Empirical evidence from a study in China shows that sunny and rainy weather positively impacts daily sales compared to cloudy weather. This suggests that certain weather conditions can boost consumer spending​​. [ScienceDirect]
- Research from the San Francisco Federal Reserve indicates that weather effects on store sales are persistent and not merely due to shifts in timing or location of purchases by consumers​​. [San Francisco Fed]
- Studies have shown that various weather elements like temperature, humidity, snowfall, and especially sunlight, can impact retail sales. Sunlight has been found to particularly affect mood, which in turn influences consumer spending habits​​. [ScienceDirect]
- The impact of weather can vary greatly, affecting daily sales by as much as 23.1% based on the store location and up to 40.7% depending on the sales theme, highlighting the significant influence of both extreme and favorable weather conditions​​. [Journal of Retail and Consumer Services]
- Weather Unlocked reports that weather conditions can predict consumer demand with high accuracy, such as a 1-degree rise in temperature can increase the demand for certain products like fizzy drinks by 22%, while decreasing demand for others such as porridge by 60%​​. [WeatherUnlocked]

<P>Using real-time weather data as exemplified in the CLIMA project isn't just about tapping into a trend; it's about harnessing crucial environmental intelligence to make more informed, proactive decisions. It's a step towards sustainability and climate-conscious operations, aligning business practices with the larger global shift towards acknowledging and addressing the challenges posed by climate change.
The CLIMA project is not just about the technical marvel of integrating data across platforms; it's about the foresight and responsibility of incorporating environmental factors into the core business strategy of any business. This approach can lead to brands being seen as leaders in climate adaptation, potentially influencing industry standards and consumer expectations. The project intends to be part of a larger movement that prioritizes not only economic efficiency but also environmental awareness and sustainable practices.
## FORSEEN USE CASES
- Offers for items regularly consumed in certain conditions (cold soft drinks in hot conditions, coffee/ tea beverages in cold conditions)
- Offers for items regularly required to attend certain conditions (rain protection gear when pouring, 
- Information suggestions to make use of items/ services already purchased / contracted (off the counter medication usage to prevent health problems under certain conditions, or geared to enhance comfort usage: bought a blanket? now is the time to show us how you are enjoy it with this chilled up weather).
- Suggestions of behaviour changes to make the most of certain conditions (energy efficiency tips for high electricity consumption appliances when the days are longer or shorter during summer and winter correspondingly).
- Damage / hazard prevention from lack or over use of products in certain climate conditions (sunblock!)

Marketing-wise, non of this rings new. What is definitively new though is the ability to respond in real time to the impredictable shifting conditions of weather to enhance the individual customers experience with your brand! By blending weather conditions data with additional demographic, behavioral and transactional data points made available through Twilio Segment, businesses are now able to build further TIMELINESS strength into their marketing strategy.
## PRE-RELEASE USE CASE
USE CASE FOCUS: The business should be able to implement a running solution where if in the STORE DATAPOINT it begins to rain (ie: rain < 1024), for every CUSTOMER PROFILE on Twilio Segment (ETLd in AWS S30) whose locationLatitude & locationLongitude is within a half-mile radius from the STORE DATAPOINTs locationLatitude & locationLongitude, THEN update the CUSTOMER PROFILE attribute "alertRain" to TRUE (and rETL it back to Twilio Segment to activate any engagement desired). When the value for rain = 1024 back again, the the CUSTOMER PROFILE attribute "alertRain" should be updated back again to FALSE (and rETL it back to Twilio Segment to activate any engagement desired). 
## What does each Sensor measure
### A. The DHT11 Temperature & Humidity Sensor: 
Measures the Temperature and Humidity of the surrounding air. The DHT11 is a low-cost digital sensor that uses Digital Signal Acquisition to convert the temperature and humidity into a digital reading. The DHT11 has four pins, one of which is used for serial data communication. The DHT11 can measure: https://www.circuitbasics.com/how-to-set-up-the-dht11-humidity-sensor-on-an-arduino/
1. Temperature: 0°C to 50°C, with a maximum accuracy of ±2°C.
2. Humidity: 20% to 90% relative humidity; which is the amount of water vapor in the air compared to the saturation point of water vapor in the air.
The DHT11 connects to the Arduino's digital IO pin. The Arduino reads the temperature and humidity every second and sends the data to the serial port. 
### B. The Rain Sensor: AKA Raindrop Detector
detects water that completes the circuits on its sensor boards' printed leads. The sensor board acts as a variable resistor that changes from 100k ohms when wet to 2M ohms when dry. The wetter the board, the more current that will be conducted. Considers a Potentiometer for sensitivity adjustment of the Analog Output (DO).
### C. Light Sensor: 
A Photoresistor light sensor in Arduino measures the amount of light in an environment. It's also known as a photocell or light dependent resistor. Photoresistors are analog sensors that change resistance based on the amount of light that hits them. When it's dark, the resistor has a high resistance of up to 10 megohms. When it's light, it has a few hundred ohms of resistance. In digital reads though, the measure has two values: 1 light, 0 dark, the set threshold in this case is 600 Ohms which is the point when sunset begins to happen based on initial analog measurements made.
I was aware of the loss of granular data from using the Analog pin for the light sensor, but provided we only have one single Analog pin on the NodeMCU, then i gave priority to the rain reading in that case. RAIN is a more unpredictable factor, rather than LIGHT which is a bit more predictable at least to be able to set the threshold. With the threshold defined, if it gets dark earlier or later in the day due to seasonal stationality then we don't loose much insightful data to act upon after all... it is all about when it gets darker and not about degrees of darkness (like in the case of rain which both: “When” and “How Much” do matter). 
### ARDUINO IDE SETTINGS
- Baud(115,200)
- WiFi 2.4Ghz -> Huesped1 / Pisha069
### ARDUINO DESKTOP IDE TESTING AGENDA
- [Y] GENERAL_BLANK
- [Y] GENERAL_BLINK_TEST
- [Y] WIFI_CONNECTION_TEST
- [Y] WIFI_SCAN_TEST
- [Y] RTC_TIMESTAMP_DATE_TIME
- [Y] RTC_TIMESTAMP_DATE_PAST_TEMP
- [Y] DHT_UNIFIED_SENSOR_TEST
- [Y] RAIN_SENSOR_JSON_TEST
- [Y] LIGHT_SENSOR_TEST
* These files are accessible at https://github.com/Noospheracr/CLIMA
