
#include <QApplication>

#include "iat-forge/forge-session.h"
#include "iat-forge/forge-runtime.h"
#include "iat-forge/forge-api-workflow.h"

#include <QFileDialog>

#include <QProcessEnvironment>

#define VALUE2(x) value(#x, #x)

void parse_default_workflow(Forge_API_Workflow& fw)
{
 auto envs = QProcessEnvironment::systemEnvironment();

 fw.parse_calls(R"(
   .; dowload a file ... ;.
  set-client-id $ %1 ;.
  set-client-secret $ %2 ;.
  load-ssl-libraries $ %3;%4 ;.
  get-access-token ;.
  check-bucket $ b3 ;.
  report-current-bucket ;.
  get-download-file-name ;.
  check-download-file ;.

 )"_q.arg(envs.VALUE2(FORGE_CLIENT_ID)).arg(envs.VALUE2(FORGE_CLIENT_SECRET))
   .arg(LIBCRYPTO_FILE_NAME).arg(LIBSSL_FILE_NAME));
}

int main(int argc, char *argv[])
{
 QApplication app(argc, argv);

 Forge_Session fs;
 QPair<Forge_Runtime*, Forge_API_Workflow*> pr = init_forge(fs);


 QString path = QFileDialog::getOpenFileName(nullptr, "Select Workflow", DEFAULT_UPLOAD_FOLDER);

 if(path.isEmpty())
 {
  qDebug() << "No workflow selected; running default.";
  parse_default_workflow(*pr.second);
 }
 else
   pr.second->parse_calls_from_file(path);

 int& result = pr.second->run_calls([&app]()
 {
  qDebug() << "Done.";
  app.exit();
  return 0;
 });
 app.exec();
// qDebug() << "result: " << result;
 return result;
}

