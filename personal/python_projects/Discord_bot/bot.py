import discord
import responses


async def send_message(message, user_message, is_private):
    try:
        response = responses.get_response(user_message)
        print('Action/ Output: ', response)
        if response:
            await message.author.send(response) if is_private else await message.channel.send(response)
    except Exception as e:
        print(e)


def run_discord_bot():
    TOKEN = '################################'
    intents = discord.Intents.default()
    intents.message_content = True
    client = discord.Client(intents=intents)

    @client.event
    async def on_ready():
        print(f'{client.user} is now running')

    @client.event
    async def on_message(message):
        if message.author == client.user:
            return
        username = str(message.author)
        user_message = str(message.content)
        channel = str(message.channel)

        print(f'{username} said "{user_message}"')

        if user_message[0] == 'l':
            user_message = user_message[1:]
            await send_message(message, user_message, is_private=False)
        #else:
        #    await send_message(message, user_message, is_private=True)
        # this sends a message private if it doesnt contain the l so i commented it out

    client.run(TOKEN)


