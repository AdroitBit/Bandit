from html.parser import HTMLParser
import os
os.chdir(os.path.dirname(os.path.abspath(__file__)))

class MyHTMLParser(HTMLParser):
    def handle_starttag(self, tag, attrs):
        print("Encountered a start tag:", tag)

    def handle_endtag(self, tag):
        print("Encountered an end tag :", tag)

    def handle_data(self, data):
        print("Encountered some data  :", data)

parser = MyHTMLParser()
parser.feed(open("test_case1.xml","r").read())