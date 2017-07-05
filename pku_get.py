import urllib
import urllib2   
import re   
from bs4 import BeautifulSoup  
from distutils.filelist import findall


def getPage(url):     
    request = urllib2.Request(url)  
    response = urllib2.urlopen(request)  
    return response.read()
if __name__ == "__main__":
    f = open("archive_map.arc", "w")
    for volid in range(1, 32) :
        left = 1000 + (volid - 1) * 100
        right = left + 100
        # print (left , right)
        volid = str(volid)
        url='http://poj.org/problemlist?volume=' + volid
        result = getPage(url)
        soup = BeautifulSoup(result,"html.parser")
        for idname in range(left, right) :
            print idname
            idname = str(idname)
            retstring = soup.find(href = "problem?id=" + idname)
            print retstring.index('>')
