https://community.arm.com/developer/tools-software/oss-platforms/w/docs/525/device-tree
Step 1: Install device tree compiler

	sudo apt-get install device-tree-compiler

Step 2: "Decompile" the device tree blob into an device tree source

	dtc -I dtb -O dts  -o output.dts input.dtb 

Step 3: Add the code below to DTS and compile it into an DTB

```
...
	othernode: othernode{
		cell-property = < prop >;
	};
	      testdevdrv {
			 compatible = "test, mytestdevice";
			 number_property = <1>;
			 string_property = <"Hello world">;
			 child-node1 = { 
					child-property = < &othernode>;
			};
	      };

...
```

Step 3.1: Compile the data tree source into an data tree blob

	dtc -O dtb -I dts  output.dtb input.dts

Step 4:Created driver and an Makefile to create the .ko module

	make

Insert the .ko module

	insmod tema9.ko
	
Remove the .ko module
	
	rmmod tema9.ko
	


