#include <iostream>
#include <string>

// --------- Low-level module ---------
class EmailSender {
public:
    void SendEmail(string to, const string msg) {
        std::cout << "[EMAIL] " << to << " : " << msg << "\n";
    }
};

// --------- High-level module ---------
class MessageService {
    EmailSender sender; // بيعتمد على التفاصيل مباشرة او الجزء الاسفل
public:
    void NotifyUser(string user, string msg) {
        sender.SendEmail(user, msg); // مربوط بالـ Low-level
    }
};
//هنا لو حبيت اضيف اي داله تانيه هطر اني اعمل شرط وده غلط 
int main() {
    MessageService service;
    service.NotifyUser("Ali", "Hello Email!");
    return 0;
}

//<-------------------------------solution with DIP--------------------------->

// --------- Interface (Abstraction) الواجهه ---------
class IMessageSender {
public:
    virtual void Send(string to, string msg) = 0;
    virtual ~IMessageSender() {}
};

// --------- Low-level modules ---------
class EmailSender : public IMessageSender {
public:
    void Send(string to, string msg) override {
        std::cout << "[EMAIL] " << to << " : " << msg << "\n";
    }
};

class SMSSender : public IMessageSender {
public:
    void Send(string to, const string msg) override {
        std::cout << "[SMS] " << to << " : " << msg << "\n";
    }
};

// --------- High-level module ---------
class MessageService {
    IMessageSender* sender; 
public:
    void SetSender(IMessageSender* s) {
        sender = s;
    }

    void NotifyUser(string user, const string msg) {
        sender->Send(user, msg);
    }
};
//هنا لو حبيت اضيف اي داله هيكون سهل لاني معايا اصلا الاوبجيكت وفيه كل الدوال اللي فيه 

int main() {
    MessageService service;

    EmailSender email;
    service.SetSender(&email);
    service.NotifyUser("Ali", "Hello Email!");

    SMSSender sms;
    service.SetSender(&sms);
    service.NotifyUser("Omar", "Hello SMS!");

    return 0;
}
