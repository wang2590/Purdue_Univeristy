
import re
from uuid import UUID

def getUrlParts(url):
    expr = r"//(?P<base>(\w|\-)+\.(\w|\-)+\.(\w|\-)+)/(?P<controller>\w*)/(?P<action>\w*)\?"
    matches = re.search(expr, url)
    base = matches.group("base")
    control = matches.group("controller")
    action = matches.group("action")
    tup = (base, control, action)
    return tup

def getQueryParameters(url):
    lists  = re.findall(r"([\w\.\-]*)=([\w\.\-]*)&*",url)
    return lists

def getSpecial(s, letter):
    expr = r"\b({0}\w*[^{0}\W]|[^{0}\W]\w*{0})\b".format(letter)
    match = re.findall(expr, s, re.I)
    return match

def getRealMAC(s):
    expr = r"(((([a-fA-F0-9]{2})(-|:)){5})([a-fA-F0-9]{2}))"
    match = re.search(expr, s, re.I)
    if match:
        return match.group(0)
    else:
        return None


def getRejectedEntries():
    lists = []
    with open("Employees.txt", 'r') as file:
        data = file.readlines()
        for line in data:
            expr = r"^((\w+\s\w+)|(\w+,\s\w+))[,; ]+$"
            match = re.search(expr, line)
            if match:
                x = match.groups()
                test = x[0]
                if ',' in test:
                    expr = r"\w+"
                    m = re.findall(expr, test)
                    fo = "{0} {1}".format(m[1], m[0])
                    lists.append(fo)
                else:
                    lists.append(str(test))
    return sorted(lists)

def getEmployeesWithStates():
    dic={}
    with open("Employees.txt", 'r') as f:
        data = f.readlines()
        for line in data:
            expr = r"^(([a-zA-z]+\s[a-zA-z]+)|([a-zA-z]+,\s[a-zA-z]+)).*?([a-zA-Z ]+)$"
            match = re.search(expr, line)
            if match:
                x = match.groups()
                test = x[0]
               # print(test)
                match2 = re.search(r"(?P<last>[A-Za-z]+),\s(?P<first>[A-Za-z]+)", str(test))
                value2 = x[3]

                if match2:
                    last = match2.group("last")
                    first = match2.group("first")
                    name = first + " " + last
                else:
                    name =str(test)

                dic[name] = value2
    return dic

if __name__ == "__main__":
    #url = "http://www.purdue.edu/Home/Calendar?Year=2016&Month=September&Semester=Fall"
    #print(getUrlParts(url))
    #url = "http://www.google.com/Math/Const?Pi=3.14&Max_Int=65536&What_Else=Not-Here"
    #print(getQueryParameters(url))
    #s = "The TART program runs on Tuesdays and Thursdays, but it does not start until next week."
    #print(getSpecial(s, 't'))
    #s = 'An example of a MAC address is 58:1C:0A:6E:39:4D.'
    #print(getRealMAC(s))
    #print(finddata())
    print(getRejectedEntries())
    #print(getEmployeesWithIDs())
    #print(getEmployeesWithStates())