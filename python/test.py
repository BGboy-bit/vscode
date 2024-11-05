import feedparser
import json

# 解析RSS源
rss_url = "https://podcasts.subsplash.com/v88jzfb/podcast.rss"
feed = feedparser.parse(rss_url)

# 将解析结果转换为字典然后转换为JSON
feed_dict = {
    "feed": {
        "title": feed.feed.title,
        "link": feed.feed.get("link", ""),
        "description": feed.feed.get("description", ""),
        "episodes": []
    }
}

for entry in feed.entries:
    episode = {
        "title": entry.title,
        "link": entry.get("link", ""),
        "description": entry.get("description", ""),
        "published": entry.get("published", ""),
    }
    feed_dict["feed"]["episodes"].append(episode)

# 转换为JSON字符串
feed_json = json.dumps(feed_dict, ensure_ascii=False, indent=2)

# 打印或保存JSON
print(feed_json)
