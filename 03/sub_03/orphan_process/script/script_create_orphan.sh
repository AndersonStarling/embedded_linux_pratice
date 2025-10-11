# Param
PROGRAM=/home/ntai/Linux_Embedded/linux_course/embedded_linux_pratice/03/sub_03/orphan_process/output/process

# Run the script

# Run the program under background
${PROGRAM} &

ps -aux | grep "/sbin/init"
