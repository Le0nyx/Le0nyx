import discord
from discord import app_commands
from discord.ext import commands
import random
import praw
from googletrans import Translator
import requests
import time


#link  =  #################
#TOKEN = ################

bot = commands.Bot(command_prefix="!", intents= discord.Intents.all())


@bot.event
async def on_ready():
    try:
        synced = await bot.tree.sync()
        print(f"synced {len(synced)} commands")
    except Exception as e:
        print(e)
    print(f'Logged in as {bot.user.name}')
    print('------')
    # Find the guild (server) where you want to run the /hello command
    guild_id = '############'  # Replace YOUR_GUILD_ID with the desired guild (server) ID
    guild = bot.get_guild(guild_id)
    if guild:
        # Find the channel where you want to run the /hello command
        channel_id = '##################'  # Replace YOUR_CHANNEL_ID with the desired channel ID
        channel = guild.get_channel(channel_id)
        if channel:          
            message_content = "# --------------------\n# PC TURNED ON \n /hello"
            message = await channel.send(message_content)

def get_weather(api_key, city):
    base_url = "http://api.openweathermap.org/data/2.5/weather?"
    complete_url = f"{base_url}q={city}&appid={api_key}&units=metric"

    response = requests.get(complete_url)
    weather_data = response.json()

    if weather_data["cod"] == 200:
        weather = weather_data["weather"][0]["description"]
        temperature = weather_data["main"]["temp"]
        humidity = weather_data["main"]["humidity"]
        wind_speed = weather_data["wind"]["speed"]
        return {
            "Weather": weather,
            "Temperature": temperature,
            "Humidity": humidity,
            "Wind Speed": wind_speed
        }
    else:
        return None  # Return None or handle error cases accordingly

@bot.tree.command(name="hello")
async def hello(interaction:discord.Interaction):
    api_key = '#######################'  # Replace with your OpenWeatherMap API key
    city_name = "Brixen"  # Replace with the city you want to get the weather for

    weather_info = get_weather(api_key, city_name)
    if weather_info:
        weather_message = (
            f"# Hello \n"
            f"Weather in {city_name}:\n\n"
            f"Description:      {weather_info['Weather']}\n"
            f"Temperature:    {weather_info['Temperature']}°C\n"
            f"Humidity:         {weather_info['Humidity']}%\n"
            f"Wind Speed:     {weather_info['Wind Speed']} m/s"
        )
        await interaction.response.send_message(weather_message)

@bot.tree.command(name="weahter")
@app_commands.describe(city_for_weather = "Enter the City name for the weather")
async def weather(interaction: discord.Interaction, city_for_weather: str):
    api_key = '################################'  # Replace with your OpenWeatherMap API key
    city_name = city_for_weather  # Replace with the city you want to get the weather for
    
    weather_info = get_weather(api_key, city_name)
    if weather_info:
        weather_message = (
            f"# Weather in {city_name}:\n\n"
            f"Description:      {weather_info['Weather']}\n"
            f"Temperature:    {weather_info['Temperature']}°C\n"
            f"Humidity:         {weather_info['Humidity']}%\n"
            f"Wind Speed:     {weather_info['Wind Speed']} m/s"
        )
        await interaction.response.send_message(weather_message)


@bot.tree.command(name="badge")
async def badge(interaction: discord.Interaction):
    await interaction.response.send_message("Edit your Bot here if needed: \n https://discord.com/developers/active-developer")

@bot.tree.command(name="help")
async def help(interaction: discord.Interaction):
    await interaction.response.send_message("`I have following commands! \n \t \t \t \t     \n - help \t  (Shows Information) \n - hello \t (Says Hello) \n - meme \t  (Sends random Meme from Reddit)\n - translate  (translates any language into English)\n - random \t(Number from 1-10)`")

@bot.tree.command(name="random")
async def help(interaction: discord.Interaction):
    await interaction.response.send_message(str(random.randint(1, 10)))


@bot.tree.command(name="meme")
async def help(interaction: discord.Interaction):
    # get a link from reddit with a random meme
    reddit = praw.Reddit(client_id='#################',
                         client_secret='################',
                         user_agent='###########')
    # choose a subreddit
    reddit_lists = ['dankmemes', 'memes', 'ComedyCemetery', 'MemeEconomy']
    choice = reddit_lists[random.randint(0, 3)]
    subreddit = reddit.subreddit(choice)
    # get a random post from the subreddit
    random_post = random.choice(list(subreddit.hot(limit=99)))
    # get the URL of the post
    post_url = random_post.url
    await interaction.response.send_message(str(post_url))


@bot.tree.command(name="translate")
@app_commands.describe(translate_into_english = "Enter the Sentence to translate")
async def translate(interaction: discord.Interaction, translate_into_english: str):
    translator = Translator()
    text = str(translate_into_english)
    detect_language = translator.detect(text).lang
    tranlated_text = translator.translate(text, dest='en').text
    language_printer = (f"Translated ({detect_language}): {tranlated_text}")
    await interaction.response.send_message(language_printer)


def check_internet_connection():
    try:
        # Try to make a request to a reliable website (e.g., Google)
        response = requests.get("http://www.google.com")
        if response.status_code == 200:
            return True
    except requests.ConnectionError:
        pass
    return False
while True:
    if check_internet_connection():
        print("Internet connection is available.")
        break
    else:
        print("No internet connection. Retrying in 10 seconds...")
        time.sleep(10)



if __name__ == '__main__':
    bot.run("#################")
