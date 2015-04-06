# Steamfield-Arkal-Filter-Pack-Control


This controller was needed to supervise a filter pack that is installed in a remote location.
The filter pack will monitor the differential pressure over a series of filter packs, if the pressure gets too high the filter pack will 
initiate a series of back flushes. 

The filter pack is deficient in that if it keeps flushing we need to filter to alarm and to open a bypass valve.

The filter controller was designed to monitor differential pressure input from a pressure sensor.
The controller also monitors the filter flush commands.

The firmware monitors for a high diff and filter run commands and alarms and bypasses the filter if required. 


