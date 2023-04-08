read -p "Enter your password: " password
if [ ${#password} -ge 8 ] && [[ $password =~ [a-z] ]] && [[ $password =~ [A-Z] ]] && [[ $password =~ [0-9] ]] && [[ $password =~ [_] ]];
then
    echo "Strong Password"
else
echo "Weak Password"
fi