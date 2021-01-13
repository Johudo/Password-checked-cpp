# Password checker

Standart password: **password**

To change password write in *password.txt* MD5 hash of your new password

```
make all
./password-checker
cppcheck --enable=all main.cpp --suppress=missingIncludeSystem
```
