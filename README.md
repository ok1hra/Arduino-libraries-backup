# Arduino-libraries-backup

## Backup /hardware/espressif subdirectory
```
cd ~/Arduino/hardware/espressif/esp32
git clone https://github.com/espressif/arduino-esp32.git
cd <repository-name>
git checkout c2c8d189928386c872aa6cd7ba7a87c8019c5663
```


```
> ~/Arduino/hardware/espressif/esp32$ git remote -v
> origin	https://github.com/espressif/arduino-esp32.git (fetch)
> origin	https://github.com/espressif/arduino-esp32.git (push)
> 
> ~/Arduino/hardware/espressif/esp32$ git rev-parse HEAD
> c2c8d189928386c872aa6cd7ba7a87c8019c5663
> 
> ~/Arduino/hardware/espressif/esp32$ git rev-parse --short HEAD
> c2c8d1899
> 
> ~/Arduino/hardware/espressif/esp32$ git branch --show-current
> master
```
