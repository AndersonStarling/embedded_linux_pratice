# red
dd if=/dev/zero bs=153600 count=1 | tr '\000' '\370\000' > /dev/fb1
sleep 2

# green
dd if=/dev/zero bs=153600 count=1 | tr '\000' '\007\340' > /dev/fb1
sleep 2

# blue
dd if=/dev/zero bs=153600 count=1 | tr '\000' '\037\000' > /dev/fb1
sleep 2

# white
dd if=/dev/zero bs=153600 count=1 | tr '\000' '\377' > /dev/fb1
sleep 2
