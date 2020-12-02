Install device-tree-compiler

	sudo apt-get install device-tree-compiler

Get the device tree blob and convert into an device tree source

	dtc -I dtb -O dts  -o output.dts input.dtb 

Add into the device tree source an node representing the new device

```
...
	othernode: othernode{
		cell-property = < 1 2 3 4>;
	};
	      testdevdrv {
			 compatible = "test, mytestdevice";
			 number_property = <1234>;
			 string_property = <"Salut">;
			 child-node1 = { 
					child-property = < &othernode>;
			};
	      };

...
```

Compile the data tree source into an data tree blob
	dtc -O dtb -I dts  output.dtb input.dts

Created an simple driver testdriver.c and an Makefile to create the .ko module
	make


Insert the .ko module
	insmod testdriver.ko
	
More info at : https://elinux.org/Device_Tree_Usage
https://elinux.org/Device_Tree_Reference

Remove the .ko module
	rmmod testdriver.ko
	
