import re

html_content = """
<html>
<head>
   <title>Sample Page</title>
</head>
<body>
   <h1>Welcome to the Sample Page</h1>
   <p>This is a paragraph on the sample page.</p>
</body>
</html>
"""
pattern = r'<title>(.*?)</title>'
match = re.search(pattern, html_content, re.IGNORECASE)
title_content = match.group(1) 
print(title_content)