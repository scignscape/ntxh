#ifndef IMAGE_EDITOR_ICOMMAND_H
#define IMAGE_EDITOR_ICOMMAND_H

class QAction;


class ICommand {

protected:

 QAction* force_redo_;

public:
    virtual void execute() = 0;

    virtual void undo() = 0;

    virtual void redo() = 0;

    virtual ~ICommand() = default;

 void force_redo(QAction* action)
 {
  force_redo_ = action;
 }

 virtual void force_redo(){};


};

#endif //IMAGE_EDITOR_ICOMMAND_H
