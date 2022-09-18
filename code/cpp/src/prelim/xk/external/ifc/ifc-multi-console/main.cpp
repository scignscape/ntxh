
class QApplication;

extern int ifc_convert_run_main(QApplication* qapp);

#if defined(_MSC_VER) && defined(_UNICODE)
extern int ifc_convert_run_main(int argc, wchar_t** argv, QApplication* qapp = nullptr);
int ifc_convert_wmain(int argc, wchar_t** argv)
{
#else

extern int ifc_convert_run_main(int argc, char** argv, QApplication* qapp = nullptr);
int main(int argc, char** argv)
{
 return ifc_convert_run_main(argc, argv);
}
#endif
