import random
import praw
from googletrans import Translator



def get_response(message) -> str:
    # the l gets already removed in the bot.py

    if message == 'help':
        return '`I have following commands! \n \t \t \t \t     \n - lhelp \t  (Shows Information) \n - lhello \t (Says Hello) \n - lmeme \t  (Sends random Meme from Reddit)\n - ltranslate  (translates any language into English)\n - lrandom \t(Number from 1-10)`'

    if message == 'hello':
        return "Hello there"
    
    if message == 'random':
        return str(random.randint(1, 10))

    if message == 'meme':
        #get a link from reddit with a random meme
        reddit = praw.Reddit(client_id='##############',
                             client_secret='############',
                             user_agent='##########')
        # choose a subreddit
        reddit_lists = ['dankmemes', 'memes',  'ComedyCemetery',  'MemeEconomy']
        choice = reddit_lists[random.randint(0,3)]
        subreddit = reddit.subreddit(choice)

        # get a random post from the subreddit
        random_post = random.choice(list(subreddit.hot(limit=99)))

        # get the URL of the post
        post_url = random_post.url

        print(post_url)
        return str(post_url)

    if message[0:9] == 'translate':
        translator = Translator()
        text = message
        detect_language = translator.detect(text).lang
        translated_text = translator.translate(text, dest='en').text
        print(detect_language)
        language_printer = (f"Translated ({detect_language}): {translated_text[10:]}")

        return language_printer
