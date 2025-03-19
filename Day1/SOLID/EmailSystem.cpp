using System;
using System.Collections.Generic;

public abstract class NotificationChannel
{
    public abstract void SendNotification(string message);
}

public class EmailNotification : NotificationChannel
{
    public override void SendNotification(string message)
    {
        Console.WriteLine("Sending Email: ");
        Console.WriteLine("Subject: Appointment Confirmation");
        Console.WriteLine("Body: " + message);
        Console.WriteLine("Attachments: None");
    }
}

public class SMSNotification : NotificationChannel
{
    public override void SendNotification(string message)
    {
        Console.WriteLine("Sending SMS: ");
        Console.WriteLine("Message: " + message.Substring(0, Math.Min(160, message.Length))); // SMS is limited to 160 characters
    }
}

public class PushNotification : NotificationChannel
{
    public override void SendNotification(string message)
    {
        Console.WriteLine("Sending Push Notification: ");
        Console.WriteLine("Message: " + message);
        Console.WriteLine("Button: Confirm Appointment");
    }
}

public class NotificationService
{
    private List<NotificationChannel> channels = new List<NotificationChannel>();

    public void AddChannel(NotificationChannel channel)
    {
        channels.Add(channel);
    }

    public void SendNotifications(string message)
    {
        foreach (var channel in channels)
        {
            channel.SendNotification(message);
        }
    }
}

public class Program
{
    public static void Main()
    {
        var emailChannel = new EmailNotification();
        var smsChannel = new SMSNotification();
        var pushChannel = new PushNotification();

        var notificationService = new NotificationService();

        notificationService.AddChannel(emailChannel);
        notificationService.AddChannel(smsChannel);
        notificationService.AddChannel(pushChannel);

        string message = "Your appointment is confirmed for tomorrow at 10 AM.";

        notificationService.SendNotifications(message);
    }
}
