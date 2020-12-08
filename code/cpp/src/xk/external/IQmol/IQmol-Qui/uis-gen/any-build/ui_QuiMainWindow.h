/********************************************************************************
** Form generated from reading UI file 'QuiMainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QUIMAINWINDOW_H
#define UI_QUIMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAbout_QUI;
    QAction *action;
    QAction *actionNew_Input_Section;
    QAction *actionRead_Input;
    QAction *actionSave;
    QAction *actionSave_As;
    QAction *actionEdit_Preferences;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_3;
    QTabWidget *setupTabWidget;
    QWidget *SetupTab;
    QVBoxLayout *verticalLayout_10;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_25;
    QGridLayout *gridLayout;
    QComboBox *exchange;
    QLabel *label_exchange;
    QHBoxLayout *hboxLayout;
    QLabel *label_106;
    QComboBox *jobList;
    QLabel *label_job_type;
    QComboBox *job_type;
    QLabel *label_method;
    QComboBox *method;
    QLabel *label_basis;
    QComboBox *basis;
    QLabel *label_ecp;
    QLabel *label_correlation;
    QComboBox *correlation;
    QLabel *label_qui_multiplicity;
    QLabel *label_qui_charge;
    QHBoxLayout *hboxLayout1;
    QSpinBox *qui_charge;
    QSpacerItem *horizontalSpacer_20;
    QHBoxLayout *horizontalLayout_22;
    QSpinBox *qui_multiplicity;
    QSpacerItem *horizontalSpacer_21;
    QComboBox *ecp;
    QHBoxLayout *hboxLayout2;
    QToolButton *addJobButton;
    QToolButton *deleteJobButton;
    QSpacerItem *horizontalSpacer_23;
    QHBoxLayout *horizontalLayout_26;
    QPushButton *editJobSectionButton;
    QSpacerItem *horizontalSpacer_25;
    QSpacerItem *horizontalSpacer_22;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_7;
    QToolBox *toolBoxOptions;
    QWidget *pageScfControl;
    QVBoxLayout *verticalLayout_34;
    QGridLayout *_8;
    QSpinBox *scf_guess_mix;
    QLabel *label_209;
    QSpinBox *scf_convergence;
    QComboBox *scf_guess;
    QComboBox *scf_algorithm;
    QLabel *label_39;
    QCheckBox *complex;
    QLabel *label_scf_guess_mix;
    QSpinBox *scf_max_cycles;
    QLabel *label_145;
    QCheckBox *ghf;
    QLabel *label_210;
    QCheckBox *os_roscf;
    QCheckBox *dual_basis_energy;
    QLabel *label_18;
    QCheckBox *gen_scfman;
    QComboBox *basis2;
    QSpacerItem *spacerItem;
    QSpinBox *complex_mix;
    QLabel *label_complex_mix;
    QCheckBox *internal_stability;
    QCheckBox *unrestricted;
    QSpacerItem *verticalSpacer_19;
    QWidget *pageWavefunctionAnalysis;
    QVBoxLayout *verticalLayout_25;
    QGridLayout *gridLayout_13;
    QCheckBox *gui;
    QCheckBox *chelpg;
    QCheckBox *nbo;
    QSpacerItem *verticalSpacer_24;
    QWidget *AdvancedTab;
    QHBoxLayout *horizontalLayout_17;
    QTreeWidget *advancedOptionsTree;
    QStackedWidget *advancedOptionsStack;
    QWidget *AdvancedSCFControl;
    QVBoxLayout *verticalLayout_12;
    QGridLayout *gridLayout_24;
    QComboBox *purecart;
    QLabel *label_203;
    QSpinBox *mom_start;
    QComboBox *mom_method;
    QCheckBox *qui_section_swap_occupied_virtual;
    QComboBox *basis_projection_type;
    QSpinBox *rca_max_cycles;
    QLabel *label_199;
    QSpacerItem *horizontalSpacer_3;
    QSpinBox *incfock;
    QFrame *line;
    QLabel *label_85;
    QLabel *label_101;
    QSpinBox *rca_print;
    QSpinBox *rca_switch_thresh;
    QLabel *label_202;
    QLabel *label_200;
    QLabel *label_117;
    QLabel *label_201;
    QFrame *line_3;
    QCheckBox *pseudo_canonical;
    QCheckBox *direct_scf;
    QSpacerItem *spacerItem1;
    QWidget *AdvancedDIIS;
    QVBoxLayout *vboxLayout;
    QGridLayout *gridLayout1;
    QLabel *label_34;
    QLabel *label_41;
    QLabel *label_94;
    QSpinBox *diis_print;
    QSpinBox *diis_switch_thresh;
    QLabel *label_35;
    QSpinBox *diis_max_cycles;
    QLabel *label_36;
    QSpacerItem *spacerItem2;
    QHBoxLayout *hboxLayout3;
    QComboBox *diis_error_metric;
    QSpacerItem *spacerItem3;
    QSpinBox *diis_subspace_size;
    QSpacerItem *spacerItem4;
    QWidget *AdvancedPrintOptions;
    QVBoxLayout *vboxLayout1;
    QGridLayout *gridLayout2;
    QSpinBox *scf_final_print;
    QLabel *label_print_orbitals;
    QCheckBox *qui_print_orbitals;
    QLabel *label_30;
    QLabel *label_29;
    QLabel *label_43;
    QLabel *label_105;
    QSpacerItem *spacerItem5;
    QSpinBox *scf_print;
    QSpacerItem *spacerItem6;
    QSpinBox *print_orbitals;
    QSpinBox *scf_guess_print;
    QSpinBox *print_distance_matrix;
    QLabel *label_21;
    QSpinBox *pdb_print;
    QCheckBox *print_general_basis;
    QCheckBox *scf_print_frgm;
    QLabel *label_89;
    QLineEdit *write_wfn;
    QSpacerItem *spacerItem7;
    QWidget *AdvancedLargeMoleculeMethods;
    QVBoxLayout *verticalLayout_16;
    QGroupBox *groupBox_0;
    QGridLayout *gridLayout_25;
    QRadioButton *qui_use_case;
    QRadioButton *qui_cfmm;
    QRadioButton *qui_none;
    QRadioButton *qui_use_ri;
    QRadioButton *ftc;
    QStackedWidget *largeMoleculesStack;
    QWidget *LargeMoleculesNone;
    QWidget *LargeMoleculesCFMM;
    QVBoxLayout *verticalLayout_24;
    QGridLayout *gridLayout_4;
    QLabel *label_47;
    QComboBox *cfmm_grain;
    QLabel *label_46;
    QCheckBox *lin_k;
    QSpinBox *cfmm_order;
    QSpacerItem *verticalSpacer_10;
    QWidget *LargeMoleculesFTC;
    QVBoxLayout *vboxLayout2;
    QCheckBox *ftc_fast;
    QLabel *label_99;
    QHBoxLayout *hboxLayout4;
    QSpinBox *ftc_class_thresh_mult;
    QLabel *label_100;
    QSpinBox *ftc_class_thresh_order;
    QSpacerItem *spacerItem8;
    QSpacerItem *spacerItem9;
    QWidget *LargeMoleculesCASE;
    QVBoxLayout *vboxLayout3;
    QSpacerItem *spacerItem10;
    QWidget *LargeMoleculesRI;
    QVBoxLayout *verticalLayout_15;
    QGridLayout *gridLayout_12;
    QSpinBox *ari_r0;
    QCheckBox *checkBox_3;
    QLabel *label_77;
    QSpinBox *ari_r1;
    QCheckBox *checkBox_2;
    QLabel *label_55;
    QCheckBox *checkBox;
    QSpacerItem *horizontalSpacer_13;
    QSpacerItem *verticalSpacer_5;
    QSpacerItem *verticalSpacer_11;
    QWidget *AdvancedHFPT;
    QVBoxLayout *verticalLayout_13;
    QGridLayout *gridLayout_21;
    QLabel *label_3;
    QLabel *label_dfpt_xc_grid;
    QComboBox *dfpt_exchange;
    QComboBox *dfpt_xc_grid;
    QComboBox *hfpt_basis;
    QLabel *label_dfpt_exchange;
    QSpacerItem *horizontalSpacer_7;
    QSpacerItem *verticalSpacer_29;
    QWidget *AdvancedPAO;
    QVBoxLayout *vboxLayout4;
    QGridLayout *gridLayout3;
    QLabel *label_49;
    QComboBox *epao_weights;
    QLabel *label_50;
    QComboBox *pao_method;
    QComboBox *pao_algorithm;
    QHBoxLayout *hboxLayout5;
    QSpinBox *epao_iterate;
    QSpacerItem *spacerItem11;
    QLabel *label_48;
    QLabel *label_51;
    QSpacerItem *spacerItem12;
    QSpacerItem *spacerItem13;
    QWidget *AdvancedInternalStability;
    QVBoxLayout *verticalLayout_6;
    QGridLayout *gridLayout_7;
    QSpinBox *internal_stability_conv;
    QLabel *label_67;
    QSpinBox *internal_stability_roots;
    QLabel *label_61;
    QSpinBox *internal_stability_iter;
    QLabel *label_57;
    QSpinBox *internal_stability_davidson_iter;
    QLabel *label_69;
    QSpacerItem *horizontalSpacer_5;
    QRadioButton *fd_mat_vec_prod;
    QSpacerItem *verticalSpacer_4;
    QWidget *AdvancedThresholds;
    QVBoxLayout *vboxLayout5;
    QGridLayout *gridLayout4;
    QLabel *label_32;
    QSpinBox *basis_linear_dependence_thresh;
    QSpinBox *thresh;
    QLabel *label_40;
    QSpacerItem *spacerItem14;
    QLabel *label_211;
    QHBoxLayout *horizontalLayout_2;
    QComboBox *meteco;
    QSpacerItem *horizontalSpacer;
    QLabel *label_198;
    QSpinBox *varthresh;
    QSpacerItem *spacerItem15;
    QWidget *AdvancedDFT;
    QVBoxLayout *verticalLayout_49;
    QHBoxLayout *horizontalLayout_32;
    QLabel *label_2;
    QComboBox *xc_grid;
    QSpacerItem *horizontalSpacer_33;
    QCheckBox *xc_smart_grid;
    QCheckBox *fast_xc;
    QCheckBox *incdft;
    QCheckBox *mrxc;
    QGroupBox *groupBox_mrxc;
    QVBoxLayout *verticalLayout_48;
    QLabel *label_8;
    QHBoxLayout *_5;
    QSpinBox *mrxc_class_thresh_mult;
    QLabel *label_102;
    QSpinBox *mrxc_class_thresh_order;
    QSpacerItem *spacerItem16;
    QHBoxLayout *horizontalLayout_34;
    QLabel *label_7;
    QSpinBox *local_interp_order;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *spacerItem17;
    QWidget *AdvancedDispersionCorrection;
    QVBoxLayout *verticalLayout_39;
    QGridLayout *gridLayout_14;
    QLabel *label_76;
    QLabel *label_98;
    QComboBox *dft_d;
    QHBoxLayout *horizontalLayout_19;
    QDoubleSpinBox *dft_d_a;
    QSpacerItem *spacerItem18;
    QGroupBox *groupBox_dft_d;
    QGridLayout *gridLayout_17;
    QLabel *label_9;
    QLabel *label_19;
    QLabel *label_20;
    QCheckBox *dft_d3_3body;
    QSpacerItem *horizontalSpacer_34;
    QDoubleSpinBox *dft_d3_s6;
    QDoubleSpinBox *dft_d3_sr6;
    QDoubleSpinBox *dft_d3_s8;
    QSpacerItem *verticalSpacer_20;
    QWidget *AdvancedXDM;
    QVBoxLayout *verticalLayout_46;
    QGridLayout *gridLayout_15;
    QLabel *label;
    QComboBox *dftvdw_jobnumber;
    QLabel *label_dftvdw_method;
    QComboBox *dftvdw_method;
    QLabel *label_dftvdw_print;
    QComboBox *dftvdw_print;
    QHBoxLayout *horizontalLayout_28;
    QSpinBox *dftvdw_mol1natoms;
    QSpacerItem *horizontalSpacer_28;
    QLabel *label_dftvdw_mol1natoms;
    QLabel *label_dftvdw_kai;
    QHBoxLayout *horizontalLayout_29;
    QSpinBox *dftvdw_kai;
    QSpacerItem *horizontalSpacer_29;
    QLabel *label_dftvdw_alpha1;
    QLabel *label_dftvdw_alpha2;
    QHBoxLayout *horizontalLayout_30;
    QSpinBox *dftvdw_alpha1;
    QSpacerItem *horizontalSpacer_30;
    QHBoxLayout *horizontalLayout_31;
    QSpinBox *dftvdw_alpha2;
    QSpacerItem *horizontalSpacer_31;
    QSpacerItem *horizontalSpacer_9;
    QSpacerItem *verticalSpacer_26;
    QWidget *AdvancedNonlocalCorrelation;
    QVBoxLayout *verticalLayout_47;
    QGridLayout *gridLayout_16;
    QLabel *label_6;
    QLabel *label_4;
    QComboBox *nl_correlation;
    QComboBox *nl_grid;
    QSpacerItem *horizontalSpacer_35;
    QSpacerItem *verticalSpacer_27;
    QWidget *AdvancedPostHartreeFock;
    QVBoxLayout *verticalLayout_19;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_17;
    QCheckBox *qui_frozen_core;
    QGridLayout *gridLayout5;
    QLabel *label_93;
    QComboBox *core_character_print;
    QSpinBox *core_character;
    QSpinBox *n_frozen_virtual;
    QSpinBox *n_frozen_core;
    QLabel *label_234;
    QLabel *label_123;
    QLabel *label_92;
    QCheckBox *ssg;
    QCheckBox *mp2v;
    QHBoxLayout *horizontalLayout;
    QLabel *label_28;
    QComboBox *cd_algorithm;
    QSpacerItem *verticalSpacer_30;
    QWidget *AdvancedCoupledCluster;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout_8;
    QLabel *label_133;
    QLabel *label_224;
    QLabel *label_151;
    QLabel *label_155;
    QLabel *label_152;
    QLineEdit *cc_dov_thresh;
    QSpinBox *cc_max_iter;
    QSpinBox *cc_convergence;
    QSpinBox *cc_diis;
    QSpinBox *cc_diis_start;
    QLabel *label_227;
    QSpinBox *cc_print;
    QLabel *label_104;
    QSpinBox *cholesky_tol;
    QCheckBox *ccman2;
    QCheckBox *cc_ref_prop;
    QCheckBox *cc_ref_prop_te;
    QCheckBox *cc_fullresponse;
    QSpacerItem *spacerItem19;
    QCheckBox *direct_ri;
    QLabel *label_226;
    QSpinBox *cc_memory;
    QLabel *label_115;
    QSpinBox *threads;
    QCheckBox *cc_symmetry;
    QSpacerItem *verticalSpacer_7;
    QWidget *AdvancedCIS;
    QVBoxLayout *verticalLayout_11;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_9;
    QGridLayout *gridLayout6;
    QSpinBox *cis_convergence;
    QSpinBox *max_cis_subspace;
    QLabel *label_166;
    QLabel *label_22;
    QSpinBox *cis_max_cycles;
    QSpacerItem *spacerItem20;
    QLabel *label_66;
    QLabel *label_90;
    QComboBox *qui_cis_guess;
    QCheckBox *cis_dynamic_mem;
    QGroupBox *groupBox_10;
    QVBoxLayout *verticalLayout_14;
    QGridLayout *gridLayout_22;
    QLabel *label_cis_ras_cutoff_virtual;
    QLabel *label_cis_ras_cutoff_occupied;
    QDoubleSpinBox *cis_ras_cutoff_occupied;
    QLabel *label_cis_ras_type;
    QDoubleSpinBox *cis_ras_cutoff_virtual;
    QSpacerItem *horizontalSpacer_11;
    QCheckBox *cis_ras;
    QCheckBox *cis_ras_print;
    QComboBox *cis_ras_type;
    QSpacerItem *spacerItem21;
    QWidget *AdvancedROKS;
    QVBoxLayout *verticalLayout_21;
    QCheckBox *roks;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_27;
    QDoubleSpinBox *roks_level_shift;
    QSpacerItem *horizontalSpacer_10;
    QSpacerItem *verticalSpacer_32;
    QWidget *AdvancedEOM;
    QVBoxLayout *verticalLayout_4;
    QGridLayout *gridLayout_2;
    QSpacerItem *spacerItem22;
    QLabel *label_188;
    QComboBox *eom_corr;
    QGroupBox *groupBox_17;
    QGridLayout *gridLayout_3;
    QLabel *label_195;
    QSpinBox *eom_nguess_singles;
    QLabel *label_196;
    QSpinBox *eom_nguess_doubles;
    QGroupBox *groupBox_14;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout_9;
    QLabel *label_215;
    QLabel *label_162;
    QLabel *label_167;
    QSpacerItem *horizontalSpacer_8;
    QSpinBox *eom_davidson_convergence;
    QSpinBox *eom_davidson_maxvectors;
    QSpinBox *eom_davidson_max_iter;
    QLineEdit *eom_davidson_threshold;
    QLabel *label_216;
    QSpacerItem *verticalSpacer_8;
    QWidget *AdvancedADC;
    QVBoxLayout *verticalLayout_29;
    QGroupBox *adc_guess;
    QGridLayout *gridLayout_19;
    QLabel *label_197;
    QSpinBox *adc_nguess_singles;
    QLabel *label_204;
    QSpinBox *adc_nguess_doubles;
    QGroupBox *adc_davidson;
    QVBoxLayout *verticalLayout_20;
    QGridLayout *gridLayout_adc_davidson;
    QLabel *label_217;
    QLabel *label_163;
    QLabel *label_168;
    QSpacerItem *horizontalSpacer_37;
    QSpinBox *adc_davidson_conv;
    QSpinBox *adc_davidson_maxsubspace;
    QSpinBox *adc_davidson_maxiter;
    QLabel *label_218;
    QSpinBox *adc_davidson_thresh;
    QGroupBox *adc_diis;
    QVBoxLayout *verticalLayout_26;
    QGridLayout *gridLayout_adc_diis;
    QLabel *label_42;
    QSpinBox *adc_diis_start;
    QSpinBox *adc_diis_econv;
    QLabel *label_177;
    QSpinBox *adc_diis_rconv;
    QLabel *label_219;
    QLabel *label_164;
    QSpinBox *adc_diis_maxiter;
    QSpacerItem *horizontalSpacer_38;
    QLabel *label_52;
    QSpinBox *adc_diis_size;
    QSpacerItem *verticalSpacer_3;
    QWidget *AdvancedEOMStates;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_38;
    QGridLayout *gridLayout_10;
    QLineEdit *ee_states;
    QLineEdit *ee_singlets;
    QLineEdit *ee_triplets;
    QLineEdit *sf_states;
    QLineEdit *dsf_states;
    QLineEdit *dip_states;
    QLineEdit *dip_singlets;
    QLineEdit *dip_triplets;
    QLineEdit *ea_states;
    QLineEdit *eom_ea_alpha;
    QLineEdit *eom_ea_beta;
    QLineEdit *ip_states;
    QLineEdit *eom_ip_alpha;
    QLineEdit *eom_ip_beta;
    QHBoxLayout *horizontalLayout_8;
    QSpinBox *cc_frzn_core;
    QSpinBox *cc_rest_occ;
    QSpinBox *cc_rest_vir;
    QSpinBox *cc_frzn_virt;
    QSpacerItem *verticalSpacer_2;
    QWidget *AdvancedSurfaceCrossing;
    QVBoxLayout *verticalLayout_8;
    QGridLayout *gridLayout7;
    QLabel *label_33;
    QLineEdit *xopt_state_1;
    QLabel *label_73;
    QLineEdit *xopt_state_2;
    QCheckBox *xopt_seam_only;
    QSpacerItem *spacerItem23;
    QWidget *AdvancedWavefunctionAnalysis;
    QVBoxLayout *vboxLayout6;
    QCheckBox *wavefunction_analysis;
    QCheckBox *molden_format;
    QCheckBox *mm_charges;
    QCheckBox *hirshfeld;
    QHBoxLayout *hboxLayout6;
    QLabel *label_176;
    QSpacerItem *spacerItem24;
    QSpinBox *multipole_order;
    QLabel *label_114;
    QHBoxLayout *hboxLayout7;
    QComboBox *mulliken;
    QSpacerItem *horizontalSpacer_32;
    QSpacerItem *spacerItem25;
    QWidget *AdvancedPlots;
    QVBoxLayout *vboxLayout7;
    QGridLayout *gridLayout8;
    QGridLayout *gridLayout9;
    QSpinBox *qui_plots_points;
    QSpacerItem *spacerItem26;
    QLabel *label_149;
    QSpacerItem *spacerItem27;
    QComboBox *plots_grid;
    QComboBox *plots_property;
    QLabel *label_147;
    QLabel *label_148;
    QCheckBox *skip_cis_rpa;
    QSpacerItem *spacerItem28;
    QWidget *AdvancedMolecularProperties;
    QVBoxLayout *verticalLayout_35;
    QGridLayout *gridLayout10;
    QLabel *label_172;
    QLabel *label_171;
    QSpinBox *moprop_max_cycles_level_1;
    QLabel *label_170;
    QLabel *label_173;
    QSpinBox *moprop_max_cycles_level_2;
    QSpinBox *moprop_convergence_level_1;
    QSpinBox *moprop_convergence_level_2;
    QLabel *label_174;
    QSpinBox *moprop_diis_subspace;
    QSpinBox *moprop_perturbations;
    QLabel *label_79;
    QLabel *label_175;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *spacerItem29;
    QWidget *AdvancedGeometryOptimization;
    QVBoxLayout *verticalLayout_37;
    QGridLayout *gridLayout11;
    QLabel *label_44;
    QComboBox *geom_opt_hessian_update;
    QLabel *label_72;
    QComboBox *geom_opt_coordinates;
    QComboBox *geom_opt_hessian;
    QLabel *label_14;
    QSpacerItem *spacerItem30;
    QHBoxLayout *hboxLayout8;
    QSpacerItem *spacerItem31;
    QCheckBox *qui_geom_opt_fallback;
    QGridLayout *gridLayout12;
    QSpinBox *geom_opt_diis_subspace;
    QLabel *label_70;
    QLabel *label_45;
    QSpinBox *geom_opt_print;
    QLabel *label_17;
    QSpinBox *geom_opt_max_cycles;
    QSpacerItem *horizontalSpacer_17;
    QCheckBox *geom_opt_scf_guess_always;
    QCheckBox *geom_print;
    QCheckBox *geom_opt_iproj;
    QCheckBox *geom_opt_symmetry;
    QSpacerItem *spacerItem32;
    QWidget *AdvancedOptThresholds;
    QVBoxLayout *verticalLayout_36;
    QGridLayout *gridLayout13;
    QLabel *label_11;
    QSpinBox *geom_opt_tol_energy;
    QLabel *label_10;
    QLabel *label_113;
    QSpinBox *geom_opt_tol_displacement;
    QLabel *label_13;
    QSpinBox *geom_opt_tol_gradient;
    QLabel *label_15;
    QLabel *label_12;
    QLabel *label_68;
    QSpinBox *geom_opt_linear_angle;
    QSpacerItem *horizontalSpacer_15;
    QLabel *label_71;
    QDoubleSpinBox *geom_opt_max_step_size;
    QSpacerItem *verticalSpacer_22;
    QWidget *AdvancedReactionPathway;
    QVBoxLayout *verticalLayout_40;
    QGridLayout *gridLayout_11;
    QLabel *label_56;
    QLabel *label_58;
    QLabel *label_60;
    QDoubleSpinBox *rpath_max_stepsize;
    QDoubleSpinBox *rpath_tol_displacement;
    QLabel *label_59;
    QSpinBox *rpath_print;
    QHBoxLayout *hboxLayout9;
    QComboBox *rpath_coordinates;
    QSpacerItem *spacerItem33;
    QSpacerItem *spacerItem34;
    QSpacerItem *verticalSpacer_21;
    QWidget *AdvancedMolecularDynamics;
    QVBoxLayout *vboxLayout8;
    QGridLayout *gridLayout14;
    QSpinBox *aimd_moments;
    QLabel *label_103;
    QSpinBox *aimd_fock_extrapolation_order;
    QLabel *label_140;
    QLabel *label_116;
    QSpinBox *aimd_fock_extrapolation_points;
    QSpacerItem *spacerItem35;
    QSpacerItem *spacerItem36;
    QWidget *AdvancedEFPOptions;
    QVBoxLayout *verticalLayout_5;
    QCheckBox *efp;
    QCheckBox *efp_fragments_only;
    QCheckBox *efp_input;
    QSpacerItem *verticalSpacer;
    QWidget *AdvancedNMRChemicalShifts;
    QVBoxLayout *verticalLayout_41;
    QGridLayout *gridLayout15;
    QSpacerItem *spacerItem37;
    QLabel *label_110;
    QSpinBox *dscf_convergence_level_2;
    QSpinBox *dscf_max_cycles_level_2;
    QSpinBox *dscf_max_cycles_level_1;
    QLabel *label_109;
    QSpinBox *dscf_convergence_level_1;
    QLabel *label_111;
    QLabel *label_112;
    QSpinBox *dscf_diis_subspace;
    QLabel *label_107;
    QLabel *label_108;
    QCheckBox *dcpscf_perturbations;
    QSpacerItem *spacerItem38;
    QWidget *AdvancedFrequencies;
    QVBoxLayout *verticalLayout_42;
    QGridLayout *gridLayout16;
    QLabel *label_150;
    QLabel *label_88;
    QLabel *label_74;
    QLabel *label_vp;
    QHBoxLayout *hboxLayout10;
    QSpinBox *cpscf_nseg;
    QSpacerItem *spacerItem39;
    QHBoxLayout *hboxLayout11;
    QSpinBox *vibman_print;
    QSpacerItem *spacerItem40;
    QHBoxLayout *hboxLayout12;
    QSpinBox *analytic_derivative_order;
    QSpacerItem *spacerItem41;
    QDoubleSpinBox *fd_step_size;
    QLabel *label_95;
    QHBoxLayout *horizontalLayout_21;
    QSpacerItem *horizontalSpacer_36;
    QComboBox *fd_derivative_type;
    QSpacerItem *spacerItem42;
    QWidget *AdvancedQMMM;
    QVBoxLayout *vboxLayout9;
    QHBoxLayout *hboxLayout13;
    QPushButton *readChargesButton;
    QSpacerItem *spacerItem43;
    QCheckBox *gaussian_blur;
    QCheckBox *qmmm;
    QCheckBox *qmmm_charges;
    QCheckBox *link_atom_projection;
    QCheckBox *qmmm_full_hessian;
    QSpacerItem *spacerItem44;
    QWidget *AdvancedSolventModel;
    QVBoxLayout *verticalLayout_51;
    QGridLayout *gridLayout_5;
    QLabel *label_64;
    QComboBox *solvent_method;
    QGroupBox *solventGroupBox;
    QGridLayout *gridLayout_23;
    QLabel *label_b160_3;
    QLabel *label_a160;
    QDoubleSpinBox *qui_solvent_cavityradius;
    QDoubleSpinBox *qui_solvent_opticaldielectric;
    QDoubleSpinBox *qui_solvent_dielectric;
    QLabel *label_97;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_23;
    QStackedWidget *solventStack;
    QWidget *SolventNone;
    QWidget *SolventOnsager;
    QVBoxLayout *verticalLayout_27;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_37;
    QSpinBox *qui_solvent_multipoleorder;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *spacerItem45;
    QWidget *SolventPCM;
    QVBoxLayout *verticalLayout_22;
    QGridLayout *gridLayout_20;
    QHBoxLayout *horizontalLayout_13;
    QSpinBox *qui_pcm_printlevel;
    QSpacerItem *horizontalSpacer_12;
    QLabel *label_75;
    QComboBox *qui_pcm_theory;
    QLabel *label_80;
    QLabel *label_81;
    QComboBox *qui_pcm_method;
    QLabel *label_96;
    QComboBox *qui_pcm_radii;
    QSpacerItem *verticalSpacer_9;
    QWidget *SolventSVP;
    QVBoxLayout *vboxLayout10;
    QGridLayout *gridLayout_6;
    QLabel *label_f161;
    QSpinBox *qui_svp_memory;
    QLabel *label_d161;
    QSpinBox *qui_svp_cavity_conv;
    QLabel *label_e161;
    QSpinBox *qui_svp_charge_conv;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_c161;
    QSpacerItem *spacer_2;
    QComboBox *qui_svp_guess;
    QCheckBox *qui_svp_path;
    QSpacerItem *spacerItem46;
    QWidget *SolventCosmo;
    QVBoxLayout *verticalLayout_28;
    QWidget *SolventChemSol;
    QVBoxLayout *verticalLayout_53;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_162b;
    QComboBox *qui_chemsol_efield;
    QHBoxLayout *hboxLayout14;
    QLabel *label_162a;
    QSpacerItem *spacerItem47;
    QSpinBox *qui_chemsol_ngrids;
    QHBoxLayout *hboxLayout15;
    QCheckBox *qui_chemsol_print;
    QSpacerItem *spacerItem48;
    QSpacerItem *spacerItem49;
    QWidget *SolventSMx;
    QVBoxLayout *verticalLayout_52;
    QGridLayout *gridLayout_18;
    QLabel *label_65;
    QComboBox *qui_smx_solvent;
    QLabel *label_54;
    QComboBox *qui_smx_charges;
    QSpacerItem *spacerItem50;
    QWidget *AdvancedSVPGrid;
    QVBoxLayout *vboxLayout11;
    QGroupBox *groupBox;
    QVBoxLayout *vboxLayout12;
    QHBoxLayout *hboxLayout16;
    QLabel *label_128;
    QComboBox *qui_svp_nptleb;
    QCheckBox *qui_svp_intcav;
    QHBoxLayout *hboxLayout17;
    QLabel *label_129;
    QSpinBox *qui_svp_nptthe;
    QLabel *label_130;
    QSpinBox *qui_svp_nptphi;
    QGroupBox *groupBox_6;
    QVBoxLayout *vboxLayout13;
    QLabel *label_131;
    QComboBox *qui_svp_itrngr;
    QGridLayout *gridLayout17;
    QLabel *label_134;
    QLabel *label_135;
    QDoubleSpinBox *qui_svp_tranx;
    QDoubleSpinBox *qui_svp_tranz;
    QLabel *label_136;
    QDoubleSpinBox *qui_svp_trany;
    QLabel *label_132;
    QComboBox *qui_svp_irotgr;
    QGridLayout *gridLayout18;
    QDoubleSpinBox *qui_svp_rotchi;
    QLabel *label_137;
    QDoubleSpinBox *qui_svp_rotphi;
    QDoubleSpinBox *qui_svp_rotthe;
    QLabel *label_138;
    QLabel *label_139;
    QSpacerItem *spacerItem51;
    QWidget *AdvancedSymmetry;
    QVBoxLayout *vboxLayout14;
    QCheckBox *symmetry_ignore;
    QCheckBox *symmetry_integral;
    QHBoxLayout *hboxLayout18;
    QLabel *label_62;
    QSpinBox *symmetry_tolerance;
    QSpacerItem *spacerItem52;
    QLabel *label_63;
    QHBoxLayout *hboxLayout19;
    QComboBox *symmetry_decomposition;
    QSpacerItem *spacerItem53;
    QSpacerItem *spacerItem54;
    QWidget *AdvancedResources;
    QVBoxLayout *vboxLayout15;
    QGridLayout *gridLayout19;
    QLabel *label_26;
    QLabel *label_24;
    QSpinBox *max_sub_file_num;
    QLabel *label_25;
    QSpinBox *mem_static;
    QSpinBox *ao2mo_disk;
    QLabel *label_31;
    QLabel *label_23;
    QSpinBox *integrals_buffer;
    QSpinBox *mem_total;
    QSpacerItem *spacerItem55;
    QSpacerItem *spacerItem56;
    QWidget *page;
    QVBoxLayout *verticalLayout_50;
    QLabel *label_16;
    QCheckBox *cis_guess_disk;
    QSpinBox *cis_guess_disk_type;
    QSpacerItem *verticalSpacer_31;
    QGroupBox *previewOutput;
    QVBoxLayout *verticalLayout_18;
    QTextEdit *previewText;
    QHBoxLayout *hboxLayout20;
    QSpacerItem *spacerItem57;
    QLabel *label_5;
    QComboBox *serverCombo;
    QHBoxLayout *hboxLayout21;
    QPushButton *resetButton;
    QSpacerItem *spacerItem58;
    QPushButton *cancelButton;
    QPushButton *submitButton;
    QMenuBar *menubar;
    QMenu *menuFile;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1306, 855);
        MainWindow->setStyleSheet(QLatin1String(" QToolTip {\n"
"    border: 2px solid darkkhaki;\n"
"    padding: 2px;\n"
"    border-radius: 3px;\n"
"    opacity: 500;\n"
"    font-size: 12px;\n"
"    color: #000;\n"
"    background-color: #EEE;\n"
"}"));
        actionAbout_QUI = new QAction(MainWindow);
        actionAbout_QUI->setObjectName(QStringLiteral("actionAbout_QUI"));
        action = new QAction(MainWindow);
        action->setObjectName(QStringLiteral("action"));
        actionNew_Input_Section = new QAction(MainWindow);
        actionNew_Input_Section->setObjectName(QStringLiteral("actionNew_Input_Section"));
        actionRead_Input = new QAction(MainWindow);
        actionRead_Input->setObjectName(QStringLiteral("actionRead_Input"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionSave_As = new QAction(MainWindow);
        actionSave_As->setObjectName(QStringLiteral("actionSave_As"));
        actionEdit_Preferences = new QAction(MainWindow);
        actionEdit_Preferences->setObjectName(QStringLiteral("actionEdit_Preferences"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        horizontalLayout_3 = new QHBoxLayout(centralwidget);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        setupTabWidget = new QTabWidget(centralwidget);
        setupTabWidget->setObjectName(QStringLiteral("setupTabWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(setupTabWidget->sizePolicy().hasHeightForWidth());
        setupTabWidget->setSizePolicy(sizePolicy);
        setupTabWidget->setMaximumSize(QSize(900, 16777215));
        SetupTab = new QWidget();
        SetupTab->setObjectName(QStringLiteral("SetupTab"));
        verticalLayout_10 = new QVBoxLayout(SetupTab);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        frame = new QFrame(SetupTab);
        frame->setObjectName(QStringLiteral("frame"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy1);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Sunken);
        horizontalLayout_25 = new QHBoxLayout(frame);
        horizontalLayout_25->setObjectName(QStringLiteral("horizontalLayout_25"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        exchange = new QComboBox(frame);
        exchange->setObjectName(QStringLiteral("exchange"));
        exchange->setEditable(true);

        gridLayout->addWidget(exchange, 4, 1, 1, 1);

        label_exchange = new QLabel(frame);
        label_exchange->setObjectName(QStringLiteral("label_exchange"));

        gridLayout->addWidget(label_exchange, 4, 0, 1, 1);

        hboxLayout = new QHBoxLayout();
        hboxLayout->setObjectName(QStringLiteral("hboxLayout"));
        label_106 = new QLabel(frame);
        label_106->setObjectName(QStringLiteral("label_106"));

        hboxLayout->addWidget(label_106);

        jobList = new QComboBox(frame);
        jobList->setObjectName(QStringLiteral("jobList"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(jobList->sizePolicy().hasHeightForWidth());
        jobList->setSizePolicy(sizePolicy2);
        jobList->setEditable(false);

        hboxLayout->addWidget(jobList);


        gridLayout->addLayout(hboxLayout, 0, 0, 1, 2);

        label_job_type = new QLabel(frame);
        label_job_type->setObjectName(QStringLiteral("label_job_type"));
        label_job_type->setMinimumSize(QSize(71, 0));

        gridLayout->addWidget(label_job_type, 1, 0, 1, 1);

        job_type = new QComboBox(frame);
        job_type->setObjectName(QStringLiteral("job_type"));
        sizePolicy2.setHeightForWidth(job_type->sizePolicy().hasHeightForWidth());
        job_type->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(job_type, 1, 1, 1, 1);

        label_method = new QLabel(frame);
        label_method->setObjectName(QStringLiteral("label_method"));

        gridLayout->addWidget(label_method, 2, 0, 1, 1);

        method = new QComboBox(frame);
        method->setObjectName(QStringLiteral("method"));
        method->setEditable(true);

        gridLayout->addWidget(method, 2, 1, 1, 1);

        label_basis = new QLabel(frame);
        label_basis->setObjectName(QStringLiteral("label_basis"));

        gridLayout->addWidget(label_basis, 3, 0, 1, 1);

        basis = new QComboBox(frame);
        basis->setObjectName(QStringLiteral("basis"));
        basis->setEditable(true);
        basis->setMaxVisibleItems(15);

        gridLayout->addWidget(basis, 3, 1, 1, 1);

        label_ecp = new QLabel(frame);
        label_ecp->setObjectName(QStringLiteral("label_ecp"));

        gridLayout->addWidget(label_ecp, 3, 2, 1, 1);

        label_correlation = new QLabel(frame);
        label_correlation->setObjectName(QStringLiteral("label_correlation"));

        gridLayout->addWidget(label_correlation, 4, 2, 1, 1);

        correlation = new QComboBox(frame);
        correlation->setObjectName(QStringLiteral("correlation"));
        correlation->setEditable(true);

        gridLayout->addWidget(correlation, 4, 3, 1, 1);

        label_qui_multiplicity = new QLabel(frame);
        label_qui_multiplicity->setObjectName(QStringLiteral("label_qui_multiplicity"));

        gridLayout->addWidget(label_qui_multiplicity, 2, 2, 1, 1);

        label_qui_charge = new QLabel(frame);
        label_qui_charge->setObjectName(QStringLiteral("label_qui_charge"));

        gridLayout->addWidget(label_qui_charge, 1, 2, 1, 1);

        hboxLayout1 = new QHBoxLayout();
        hboxLayout1->setObjectName(QStringLiteral("hboxLayout1"));
        qui_charge = new QSpinBox(frame);
        qui_charge->setObjectName(QStringLiteral("qui_charge"));

        hboxLayout1->addWidget(qui_charge);

        horizontalSpacer_20 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout1->addItem(horizontalSpacer_20);


        gridLayout->addLayout(hboxLayout1, 1, 3, 1, 2);

        horizontalLayout_22 = new QHBoxLayout();
        horizontalLayout_22->setObjectName(QStringLiteral("horizontalLayout_22"));
        qui_multiplicity = new QSpinBox(frame);
        qui_multiplicity->setObjectName(QStringLiteral("qui_multiplicity"));
        qui_multiplicity->setMinimum(1);
        qui_multiplicity->setSingleStep(2);

        horizontalLayout_22->addWidget(qui_multiplicity);

        horizontalSpacer_21 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_22->addItem(horizontalSpacer_21);


        gridLayout->addLayout(horizontalLayout_22, 2, 3, 1, 2);

        ecp = new QComboBox(frame);
        ecp->setObjectName(QStringLiteral("ecp"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(ecp->sizePolicy().hasHeightForWidth());
        ecp->setSizePolicy(sizePolicy3);

        gridLayout->addWidget(ecp, 3, 3, 1, 1);

        hboxLayout2 = new QHBoxLayout();
        hboxLayout2->setObjectName(QStringLiteral("hboxLayout2"));
        addJobButton = new QToolButton(frame);
        addJobButton->setObjectName(QStringLiteral("addJobButton"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/resources/icons/Add.png"), QSize(), QIcon::Normal, QIcon::Off);
        addJobButton->setIcon(icon);

        hboxLayout2->addWidget(addJobButton);

        deleteJobButton = new QToolButton(frame);
        deleteJobButton->setObjectName(QStringLiteral("deleteJobButton"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/resources/icons/Remove.png"), QSize(), QIcon::Normal, QIcon::Off);
        deleteJobButton->setIcon(icon1);

        hboxLayout2->addWidget(deleteJobButton);

        horizontalSpacer_23 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout2->addItem(horizontalSpacer_23);


        gridLayout->addLayout(hboxLayout2, 0, 3, 1, 2);

        horizontalLayout_26 = new QHBoxLayout();
        horizontalLayout_26->setObjectName(QStringLiteral("horizontalLayout_26"));
        editJobSectionButton = new QPushButton(frame);
        editJobSectionButton->setObjectName(QStringLiteral("editJobSectionButton"));

        horizontalLayout_26->addWidget(editJobSectionButton);

        horizontalSpacer_25 = new QSpacerItem(10, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_26->addItem(horizontalSpacer_25);


        gridLayout->addLayout(horizontalLayout_26, 0, 2, 1, 1);

        horizontalSpacer_22 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_22, 3, 4, 1, 1);


        horizontalLayout_25->addLayout(gridLayout);


        verticalLayout_10->addWidget(frame);

        scrollArea = new QScrollArea(SetupTab);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 617, 573));
        verticalLayout_7 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        toolBoxOptions = new QToolBox(scrollAreaWidgetContents);
        toolBoxOptions->setObjectName(QStringLiteral("toolBoxOptions"));
        toolBoxOptions->setEnabled(true);
        pageScfControl = new QWidget();
        pageScfControl->setObjectName(QStringLiteral("pageScfControl"));
        pageScfControl->setGeometry(QRect(0, 0, 599, 489));
        verticalLayout_34 = new QVBoxLayout(pageScfControl);
        verticalLayout_34->setObjectName(QStringLiteral("verticalLayout_34"));
        _8 = new QGridLayout();
        _8->setObjectName(QStringLiteral("_8"));
        scf_guess_mix = new QSpinBox(pageScfControl);
        scf_guess_mix->setObjectName(QStringLiteral("scf_guess_mix"));

        _8->addWidget(scf_guess_mix, 2, 3, 1, 1);

        label_209 = new QLabel(pageScfControl);
        label_209->setObjectName(QStringLiteral("label_209"));

        _8->addWidget(label_209, 1, 0, 1, 1);

        scf_convergence = new QSpinBox(pageScfControl);
        scf_convergence->setObjectName(QStringLiteral("scf_convergence"));
        scf_convergence->setMinimum(-1);
        scf_convergence->setMaximum(20);

        _8->addWidget(scf_convergence, 0, 3, 1, 1);

        scf_guess = new QComboBox(pageScfControl);
        scf_guess->setObjectName(QStringLiteral("scf_guess"));

        _8->addWidget(scf_guess, 1, 1, 1, 1);

        scf_algorithm = new QComboBox(pageScfControl);
        scf_algorithm->setObjectName(QStringLiteral("scf_algorithm"));

        _8->addWidget(scf_algorithm, 0, 1, 1, 1);

        label_39 = new QLabel(pageScfControl);
        label_39->setObjectName(QStringLiteral("label_39"));

        _8->addWidget(label_39, 0, 2, 1, 1);

        complex = new QCheckBox(pageScfControl);
        complex->setObjectName(QStringLiteral("complex"));

        _8->addWidget(complex, 6, 0, 1, 2);

        label_scf_guess_mix = new QLabel(pageScfControl);
        label_scf_guess_mix->setObjectName(QStringLiteral("label_scf_guess_mix"));

        _8->addWidget(label_scf_guess_mix, 2, 2, 1, 1);

        scf_max_cycles = new QSpinBox(pageScfControl);
        scf_max_cycles->setObjectName(QStringLiteral("scf_max_cycles"));

        _8->addWidget(scf_max_cycles, 1, 3, 1, 1);

        label_145 = new QLabel(pageScfControl);
        label_145->setObjectName(QStringLiteral("label_145"));

        _8->addWidget(label_145, 2, 0, 1, 1);

        ghf = new QCheckBox(pageScfControl);
        ghf->setObjectName(QStringLiteral("ghf"));

        _8->addWidget(ghf, 5, 2, 1, 3);

        label_210 = new QLabel(pageScfControl);
        label_210->setObjectName(QStringLiteral("label_210"));

        _8->addWidget(label_210, 0, 0, 1, 1);

        os_roscf = new QCheckBox(pageScfControl);
        os_roscf->setObjectName(QStringLiteral("os_roscf"));

        _8->addWidget(os_roscf, 5, 0, 1, 2);

        dual_basis_energy = new QCheckBox(pageScfControl);
        dual_basis_energy->setObjectName(QStringLiteral("dual_basis_energy"));

        _8->addWidget(dual_basis_energy, 3, 2, 1, 2);

        label_18 = new QLabel(pageScfControl);
        label_18->setObjectName(QStringLiteral("label_18"));

        _8->addWidget(label_18, 1, 2, 1, 1);

        gen_scfman = new QCheckBox(pageScfControl);
        gen_scfman->setObjectName(QStringLiteral("gen_scfman"));

        _8->addWidget(gen_scfman, 4, 0, 1, 2);

        basis2 = new QComboBox(pageScfControl);
        basis2->setObjectName(QStringLiteral("basis2"));
        basis2->setEditable(false);

        _8->addWidget(basis2, 2, 1, 1, 1);

        spacerItem = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        _8->addItem(spacerItem, 0, 4, 1, 1);

        complex_mix = new QSpinBox(pageScfControl);
        complex_mix->setObjectName(QStringLiteral("complex_mix"));
        complex_mix->setMinimum(0);
        complex_mix->setValue(0);

        _8->addWidget(complex_mix, 6, 3, 1, 1);

        label_complex_mix = new QLabel(pageScfControl);
        label_complex_mix->setObjectName(QStringLiteral("label_complex_mix"));

        _8->addWidget(label_complex_mix, 6, 2, 1, 1);

        internal_stability = new QCheckBox(pageScfControl);
        internal_stability->setObjectName(QStringLiteral("internal_stability"));

        _8->addWidget(internal_stability, 4, 2, 1, 2);

        unrestricted = new QCheckBox(pageScfControl);
        unrestricted->setObjectName(QStringLiteral("unrestricted"));

        _8->addWidget(unrestricted, 3, 0, 1, 2);


        verticalLayout_34->addLayout(_8);

        verticalSpacer_19 = new QSpacerItem(20, 3, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_34->addItem(verticalSpacer_19);

        toolBoxOptions->addItem(pageScfControl, QStringLiteral("SCF Control"));
        pageWavefunctionAnalysis = new QWidget();
        pageWavefunctionAnalysis->setObjectName(QStringLiteral("pageWavefunctionAnalysis"));
        pageWavefunctionAnalysis->setGeometry(QRect(0, 0, 599, 489));
        verticalLayout_25 = new QVBoxLayout(pageWavefunctionAnalysis);
        verticalLayout_25->setObjectName(QStringLiteral("verticalLayout_25"));
        gridLayout_13 = new QGridLayout();
        gridLayout_13->setObjectName(QStringLiteral("gridLayout_13"));
        gui = new QCheckBox(pageWavefunctionAnalysis);
        gui->setObjectName(QStringLiteral("gui"));

        gridLayout_13->addWidget(gui, 0, 0, 1, 1);

        chelpg = new QCheckBox(pageWavefunctionAnalysis);
        chelpg->setObjectName(QStringLiteral("chelpg"));

        gridLayout_13->addWidget(chelpg, 0, 1, 1, 1);

        nbo = new QCheckBox(pageWavefunctionAnalysis);
        nbo->setObjectName(QStringLiteral("nbo"));

        gridLayout_13->addWidget(nbo, 1, 0, 1, 1);


        verticalLayout_25->addLayout(gridLayout_13);

        verticalSpacer_24 = new QSpacerItem(20, 52, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_25->addItem(verticalSpacer_24);

        toolBoxOptions->addItem(pageWavefunctionAnalysis, QStringLiteral("Wavefunction Analysis"));

        verticalLayout_7->addWidget(toolBoxOptions);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_10->addWidget(scrollArea);

        setupTabWidget->addTab(SetupTab, QString());
        AdvancedTab = new QWidget();
        AdvancedTab->setObjectName(QStringLiteral("AdvancedTab"));
        horizontalLayout_17 = new QHBoxLayout(AdvancedTab);
        horizontalLayout_17->setObjectName(QStringLiteral("horizontalLayout_17"));
        advancedOptionsTree = new QTreeWidget(AdvancedTab);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem(advancedOptionsTree);
        new QTreeWidgetItem(__qtreewidgetitem);
        new QTreeWidgetItem(__qtreewidgetitem);
        new QTreeWidgetItem(__qtreewidgetitem);
        new QTreeWidgetItem(__qtreewidgetitem);
        new QTreeWidgetItem(__qtreewidgetitem);
        new QTreeWidgetItem(__qtreewidgetitem);
        new QTreeWidgetItem(__qtreewidgetitem);
        QTreeWidgetItem *__qtreewidgetitem1 = new QTreeWidgetItem(advancedOptionsTree);
        new QTreeWidgetItem(__qtreewidgetitem1);
        new QTreeWidgetItem(__qtreewidgetitem1);
        new QTreeWidgetItem(__qtreewidgetitem1);
        QTreeWidgetItem *__qtreewidgetitem2 = new QTreeWidgetItem(advancedOptionsTree);
        new QTreeWidgetItem(__qtreewidgetitem2);
        QTreeWidgetItem *__qtreewidgetitem3 = new QTreeWidgetItem(advancedOptionsTree);
        new QTreeWidgetItem(__qtreewidgetitem3);
        new QTreeWidgetItem(__qtreewidgetitem3);
        QTreeWidgetItem *__qtreewidgetitem4 = new QTreeWidgetItem(__qtreewidgetitem3);
        new QTreeWidgetItem(__qtreewidgetitem4);
        new QTreeWidgetItem(__qtreewidgetitem3);
        QTreeWidgetItem *__qtreewidgetitem5 = new QTreeWidgetItem(advancedOptionsTree);
        new QTreeWidgetItem(__qtreewidgetitem5);
        new QTreeWidgetItem(__qtreewidgetitem5);
        QTreeWidgetItem *__qtreewidgetitem6 = new QTreeWidgetItem(advancedOptionsTree);
        new QTreeWidgetItem(__qtreewidgetitem6);
        new QTreeWidgetItem(advancedOptionsTree);
        new QTreeWidgetItem(advancedOptionsTree);
        new QTreeWidgetItem(advancedOptionsTree);
        new QTreeWidgetItem(advancedOptionsTree);
        new QTreeWidgetItem(advancedOptionsTree);
        new QTreeWidgetItem(advancedOptionsTree);
        new QTreeWidgetItem(advancedOptionsTree);
        new QTreeWidgetItem(advancedOptionsTree);
        new QTreeWidgetItem(advancedOptionsTree);
        advancedOptionsTree->setObjectName(QStringLiteral("advancedOptionsTree"));
        QSizePolicy sizePolicy4(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(advancedOptionsTree->sizePolicy().hasHeightForWidth());
        advancedOptionsTree->setSizePolicy(sizePolicy4);
        advancedOptionsTree->setMinimumSize(QSize(220, 0));
        advancedOptionsTree->setIndentation(12);

        horizontalLayout_17->addWidget(advancedOptionsTree);

        advancedOptionsStack = new QStackedWidget(AdvancedTab);
        advancedOptionsStack->setObjectName(QStringLiteral("advancedOptionsStack"));
        sizePolicy4.setHeightForWidth(advancedOptionsStack->sizePolicy().hasHeightForWidth());
        advancedOptionsStack->setSizePolicy(sizePolicy4);
        advancedOptionsStack->setMinimumSize(QSize(220, 0));
        advancedOptionsStack->setFrameShape(QFrame::Box);
        advancedOptionsStack->setFrameShadow(QFrame::Sunken);
        AdvancedSCFControl = new QWidget();
        AdvancedSCFControl->setObjectName(QStringLiteral("AdvancedSCFControl"));
        verticalLayout_12 = new QVBoxLayout(AdvancedSCFControl);
        verticalLayout_12->setObjectName(QStringLiteral("verticalLayout_12"));
        gridLayout_24 = new QGridLayout();
        gridLayout_24->setObjectName(QStringLiteral("gridLayout_24"));
        purecart = new QComboBox(AdvancedSCFControl);
        purecart->setObjectName(QStringLiteral("purecart"));

        gridLayout_24->addWidget(purecart, 0, 1, 1, 2);

        label_203 = new QLabel(AdvancedSCFControl);
        label_203->setObjectName(QStringLiteral("label_203"));

        gridLayout_24->addWidget(label_203, 1, 0, 1, 1);

        mom_start = new QSpinBox(AdvancedSCFControl);
        mom_start->setObjectName(QStringLiteral("mom_start"));

        gridLayout_24->addWidget(mom_start, 4, 1, 1, 1);

        mom_method = new QComboBox(AdvancedSCFControl);
        mom_method->setObjectName(QStringLiteral("mom_method"));

        gridLayout_24->addWidget(mom_method, 5, 1, 1, 2);

        qui_section_swap_occupied_virtual = new QCheckBox(AdvancedSCFControl);
        qui_section_swap_occupied_virtual->setObjectName(QStringLiteral("qui_section_swap_occupied_virtual"));

        gridLayout_24->addWidget(qui_section_swap_occupied_virtual, 6, 0, 1, 1);

        basis_projection_type = new QComboBox(AdvancedSCFControl);
        basis_projection_type->setObjectName(QStringLiteral("basis_projection_type"));

        gridLayout_24->addWidget(basis_projection_type, 1, 1, 1, 2);

        rca_max_cycles = new QSpinBox(AdvancedSCFControl);
        rca_max_cycles->setObjectName(QStringLiteral("rca_max_cycles"));

        gridLayout_24->addWidget(rca_max_cycles, 8, 1, 1, 1);

        label_199 = new QLabel(AdvancedSCFControl);
        label_199->setObjectName(QStringLiteral("label_199"));

        gridLayout_24->addWidget(label_199, 2, 0, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_24->addItem(horizontalSpacer_3, 4, 2, 1, 1);

        incfock = new QSpinBox(AdvancedSCFControl);
        incfock->setObjectName(QStringLiteral("incfock"));

        gridLayout_24->addWidget(incfock, 2, 1, 1, 1);

        line = new QFrame(AdvancedSCFControl);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout_24->addWidget(line, 3, 0, 1, 3);

        label_85 = new QLabel(AdvancedSCFControl);
        label_85->setObjectName(QStringLiteral("label_85"));

        gridLayout_24->addWidget(label_85, 10, 0, 1, 1);

        label_101 = new QLabel(AdvancedSCFControl);
        label_101->setObjectName(QStringLiteral("label_101"));

        gridLayout_24->addWidget(label_101, 9, 0, 1, 1);

        rca_print = new QSpinBox(AdvancedSCFControl);
        rca_print->setObjectName(QStringLiteral("rca_print"));

        gridLayout_24->addWidget(rca_print, 10, 1, 1, 1);

        rca_switch_thresh = new QSpinBox(AdvancedSCFControl);
        rca_switch_thresh->setObjectName(QStringLiteral("rca_switch_thresh"));

        gridLayout_24->addWidget(rca_switch_thresh, 9, 1, 1, 1);

        label_202 = new QLabel(AdvancedSCFControl);
        label_202->setObjectName(QStringLiteral("label_202"));

        gridLayout_24->addWidget(label_202, 0, 0, 1, 1);

        label_200 = new QLabel(AdvancedSCFControl);
        label_200->setObjectName(QStringLiteral("label_200"));
        sizePolicy4.setHeightForWidth(label_200->sizePolicy().hasHeightForWidth());
        label_200->setSizePolicy(sizePolicy4);

        gridLayout_24->addWidget(label_200, 4, 0, 1, 1);

        label_117 = new QLabel(AdvancedSCFControl);
        label_117->setObjectName(QStringLiteral("label_117"));

        gridLayout_24->addWidget(label_117, 5, 0, 1, 1);

        label_201 = new QLabel(AdvancedSCFControl);
        label_201->setObjectName(QStringLiteral("label_201"));

        gridLayout_24->addWidget(label_201, 8, 0, 1, 1);

        line_3 = new QFrame(AdvancedSCFControl);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        gridLayout_24->addWidget(line_3, 7, 0, 1, 3);


        verticalLayout_12->addLayout(gridLayout_24);

        pseudo_canonical = new QCheckBox(AdvancedSCFControl);
        pseudo_canonical->setObjectName(QStringLiteral("pseudo_canonical"));

        verticalLayout_12->addWidget(pseudo_canonical);

        direct_scf = new QCheckBox(AdvancedSCFControl);
        direct_scf->setObjectName(QStringLiteral("direct_scf"));

        verticalLayout_12->addWidget(direct_scf);

        spacerItem1 = new QSpacerItem(283, 16, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_12->addItem(spacerItem1);

        advancedOptionsStack->addWidget(AdvancedSCFControl);
        AdvancedDIIS = new QWidget();
        AdvancedDIIS->setObjectName(QStringLiteral("AdvancedDIIS"));
        vboxLayout = new QVBoxLayout(AdvancedDIIS);
        vboxLayout->setObjectName(QStringLiteral("vboxLayout"));
        gridLayout1 = new QGridLayout();
        gridLayout1->setObjectName(QStringLiteral("gridLayout1"));
        label_34 = new QLabel(AdvancedDIIS);
        label_34->setObjectName(QStringLiteral("label_34"));

        gridLayout1->addWidget(label_34, 0, 0, 1, 1);

        label_41 = new QLabel(AdvancedDIIS);
        label_41->setObjectName(QStringLiteral("label_41"));

        gridLayout1->addWidget(label_41, 3, 0, 1, 1);

        label_94 = new QLabel(AdvancedDIIS);
        label_94->setObjectName(QStringLiteral("label_94"));

        gridLayout1->addWidget(label_94, 4, 0, 1, 1);

        diis_print = new QSpinBox(AdvancedDIIS);
        diis_print->setObjectName(QStringLiteral("diis_print"));

        gridLayout1->addWidget(diis_print, 1, 1, 1, 1);

        diis_switch_thresh = new QSpinBox(AdvancedDIIS);
        diis_switch_thresh->setObjectName(QStringLiteral("diis_switch_thresh"));

        gridLayout1->addWidget(diis_switch_thresh, 2, 1, 1, 1);

        label_35 = new QLabel(AdvancedDIIS);
        label_35->setObjectName(QStringLiteral("label_35"));

        gridLayout1->addWidget(label_35, 1, 0, 1, 1);

        diis_max_cycles = new QSpinBox(AdvancedDIIS);
        diis_max_cycles->setObjectName(QStringLiteral("diis_max_cycles"));

        gridLayout1->addWidget(diis_max_cycles, 3, 1, 1, 1);

        label_36 = new QLabel(AdvancedDIIS);
        label_36->setObjectName(QStringLiteral("label_36"));

        gridLayout1->addWidget(label_36, 2, 0, 1, 1);

        spacerItem2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout1->addItem(spacerItem2, 0, 2, 1, 1);

        hboxLayout3 = new QHBoxLayout();
        hboxLayout3->setObjectName(QStringLiteral("hboxLayout3"));
        diis_error_metric = new QComboBox(AdvancedDIIS);
        diis_error_metric->setObjectName(QStringLiteral("diis_error_metric"));

        hboxLayout3->addWidget(diis_error_metric);

        spacerItem3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout3->addItem(spacerItem3);


        gridLayout1->addLayout(hboxLayout3, 4, 1, 1, 2);

        diis_subspace_size = new QSpinBox(AdvancedDIIS);
        diis_subspace_size->setObjectName(QStringLiteral("diis_subspace_size"));

        gridLayout1->addWidget(diis_subspace_size, 0, 1, 1, 1);


        vboxLayout->addLayout(gridLayout1);

        spacerItem4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vboxLayout->addItem(spacerItem4);

        advancedOptionsStack->addWidget(AdvancedDIIS);
        AdvancedPrintOptions = new QWidget();
        AdvancedPrintOptions->setObjectName(QStringLiteral("AdvancedPrintOptions"));
        vboxLayout1 = new QVBoxLayout(AdvancedPrintOptions);
        vboxLayout1->setObjectName(QStringLiteral("vboxLayout1"));
        gridLayout2 = new QGridLayout();
        gridLayout2->setObjectName(QStringLiteral("gridLayout2"));
        scf_final_print = new QSpinBox(AdvancedPrintOptions);
        scf_final_print->setObjectName(QStringLiteral("scf_final_print"));

        gridLayout2->addWidget(scf_final_print, 2, 2, 1, 1);

        label_print_orbitals = new QLabel(AdvancedPrintOptions);
        label_print_orbitals->setObjectName(QStringLiteral("label_print_orbitals"));

        gridLayout2->addWidget(label_print_orbitals, 4, 1, 1, 1);

        qui_print_orbitals = new QCheckBox(AdvancedPrintOptions);
        qui_print_orbitals->setObjectName(QStringLiteral("qui_print_orbitals"));

        gridLayout2->addWidget(qui_print_orbitals, 3, 0, 1, 2);

        label_30 = new QLabel(AdvancedPrintOptions);
        label_30->setObjectName(QStringLiteral("label_30"));

        gridLayout2->addWidget(label_30, 1, 0, 1, 2);

        label_29 = new QLabel(AdvancedPrintOptions);
        label_29->setObjectName(QStringLiteral("label_29"));

        gridLayout2->addWidget(label_29, 0, 0, 1, 2);

        label_43 = new QLabel(AdvancedPrintOptions);
        label_43->setObjectName(QStringLiteral("label_43"));

        gridLayout2->addWidget(label_43, 2, 0, 1, 2);

        label_105 = new QLabel(AdvancedPrintOptions);
        label_105->setObjectName(QStringLiteral("label_105"));

        gridLayout2->addWidget(label_105, 5, 0, 1, 2);

        spacerItem5 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout2->addItem(spacerItem5, 4, 0, 1, 1);

        scf_print = new QSpinBox(AdvancedPrintOptions);
        scf_print->setObjectName(QStringLiteral("scf_print"));

        gridLayout2->addWidget(scf_print, 0, 2, 1, 1);

        spacerItem6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout2->addItem(spacerItem6, 0, 3, 1, 1);

        print_orbitals = new QSpinBox(AdvancedPrintOptions);
        print_orbitals->setObjectName(QStringLiteral("print_orbitals"));

        gridLayout2->addWidget(print_orbitals, 4, 2, 1, 1);

        scf_guess_print = new QSpinBox(AdvancedPrintOptions);
        scf_guess_print->setObjectName(QStringLiteral("scf_guess_print"));

        gridLayout2->addWidget(scf_guess_print, 1, 2, 1, 1);

        print_distance_matrix = new QSpinBox(AdvancedPrintOptions);
        print_distance_matrix->setObjectName(QStringLiteral("print_distance_matrix"));

        gridLayout2->addWidget(print_distance_matrix, 5, 2, 1, 1);

        label_21 = new QLabel(AdvancedPrintOptions);
        label_21->setObjectName(QStringLiteral("label_21"));

        gridLayout2->addWidget(label_21, 6, 0, 1, 2);

        pdb_print = new QSpinBox(AdvancedPrintOptions);
        pdb_print->setObjectName(QStringLiteral("pdb_print"));

        gridLayout2->addWidget(pdb_print, 6, 2, 1, 1);


        vboxLayout1->addLayout(gridLayout2);

        print_general_basis = new QCheckBox(AdvancedPrintOptions);
        print_general_basis->setObjectName(QStringLiteral("print_general_basis"));

        vboxLayout1->addWidget(print_general_basis);

        scf_print_frgm = new QCheckBox(AdvancedPrintOptions);
        scf_print_frgm->setObjectName(QStringLiteral("scf_print_frgm"));

        vboxLayout1->addWidget(scf_print_frgm);

        label_89 = new QLabel(AdvancedPrintOptions);
        label_89->setObjectName(QStringLiteral("label_89"));

        vboxLayout1->addWidget(label_89);

        write_wfn = new QLineEdit(AdvancedPrintOptions);
        write_wfn->setObjectName(QStringLiteral("write_wfn"));

        vboxLayout1->addWidget(write_wfn);

        spacerItem7 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vboxLayout1->addItem(spacerItem7);

        advancedOptionsStack->addWidget(AdvancedPrintOptions);
        AdvancedLargeMoleculeMethods = new QWidget();
        AdvancedLargeMoleculeMethods->setObjectName(QStringLiteral("AdvancedLargeMoleculeMethods"));
        verticalLayout_16 = new QVBoxLayout(AdvancedLargeMoleculeMethods);
        verticalLayout_16->setObjectName(QStringLiteral("verticalLayout_16"));
        groupBox_0 = new QGroupBox(AdvancedLargeMoleculeMethods);
        groupBox_0->setObjectName(QStringLiteral("groupBox_0"));
        gridLayout_25 = new QGridLayout(groupBox_0);
        gridLayout_25->setObjectName(QStringLiteral("gridLayout_25"));
        qui_use_case = new QRadioButton(groupBox_0);
        qui_use_case->setObjectName(QStringLiteral("qui_use_case"));

        gridLayout_25->addWidget(qui_use_case, 0, 2, 1, 1);

        qui_cfmm = new QRadioButton(groupBox_0);
        qui_cfmm->setObjectName(QStringLiteral("qui_cfmm"));
        qui_cfmm->setChecked(true);

        gridLayout_25->addWidget(qui_cfmm, 0, 1, 1, 1);

        qui_none = new QRadioButton(groupBox_0);
        qui_none->setObjectName(QStringLiteral("qui_none"));

        gridLayout_25->addWidget(qui_none, 0, 0, 1, 1);

        qui_use_ri = new QRadioButton(groupBox_0);
        qui_use_ri->setObjectName(QStringLiteral("qui_use_ri"));

        gridLayout_25->addWidget(qui_use_ri, 1, 1, 1, 1);

        ftc = new QRadioButton(groupBox_0);
        ftc->setObjectName(QStringLiteral("ftc"));

        gridLayout_25->addWidget(ftc, 1, 0, 1, 1);


        verticalLayout_16->addWidget(groupBox_0);

        largeMoleculesStack = new QStackedWidget(AdvancedLargeMoleculeMethods);
        largeMoleculesStack->setObjectName(QStringLiteral("largeMoleculesStack"));
        QSizePolicy sizePolicy5(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(largeMoleculesStack->sizePolicy().hasHeightForWidth());
        largeMoleculesStack->setSizePolicy(sizePolicy5);
        largeMoleculesStack->setMinimumSize(QSize(0, 100));
        LargeMoleculesNone = new QWidget();
        LargeMoleculesNone->setObjectName(QStringLiteral("LargeMoleculesNone"));
        largeMoleculesStack->addWidget(LargeMoleculesNone);
        LargeMoleculesCFMM = new QWidget();
        LargeMoleculesCFMM->setObjectName(QStringLiteral("LargeMoleculesCFMM"));
        verticalLayout_24 = new QVBoxLayout(LargeMoleculesCFMM);
        verticalLayout_24->setObjectName(QStringLiteral("verticalLayout_24"));
        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        label_47 = new QLabel(LargeMoleculesCFMM);
        label_47->setObjectName(QStringLiteral("label_47"));

        gridLayout_4->addWidget(label_47, 0, 0, 1, 1);

        cfmm_grain = new QComboBox(LargeMoleculesCFMM);
        cfmm_grain->setObjectName(QStringLiteral("cfmm_grain"));
        cfmm_grain->setEditable(false);

        gridLayout_4->addWidget(cfmm_grain, 0, 1, 1, 1);

        label_46 = new QLabel(LargeMoleculesCFMM);
        label_46->setObjectName(QStringLiteral("label_46"));

        gridLayout_4->addWidget(label_46, 1, 0, 1, 1);

        lin_k = new QCheckBox(LargeMoleculesCFMM);
        lin_k->setObjectName(QStringLiteral("lin_k"));

        gridLayout_4->addWidget(lin_k, 2, 0, 1, 1);

        cfmm_order = new QSpinBox(LargeMoleculesCFMM);
        cfmm_order->setObjectName(QStringLiteral("cfmm_order"));
        QSizePolicy sizePolicy6(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(cfmm_order->sizePolicy().hasHeightForWidth());
        cfmm_order->setSizePolicy(sizePolicy6);

        gridLayout_4->addWidget(cfmm_order, 1, 1, 1, 1);


        verticalLayout_24->addLayout(gridLayout_4);

        verticalSpacer_10 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_24->addItem(verticalSpacer_10);

        largeMoleculesStack->addWidget(LargeMoleculesCFMM);
        LargeMoleculesFTC = new QWidget();
        LargeMoleculesFTC->setObjectName(QStringLiteral("LargeMoleculesFTC"));
        vboxLayout2 = new QVBoxLayout(LargeMoleculesFTC);
        vboxLayout2->setObjectName(QStringLiteral("vboxLayout2"));
        ftc_fast = new QCheckBox(LargeMoleculesFTC);
        ftc_fast->setObjectName(QStringLiteral("ftc_fast"));

        vboxLayout2->addWidget(ftc_fast);

        label_99 = new QLabel(LargeMoleculesFTC);
        label_99->setObjectName(QStringLiteral("label_99"));

        vboxLayout2->addWidget(label_99);

        hboxLayout4 = new QHBoxLayout();
        hboxLayout4->setObjectName(QStringLiteral("hboxLayout4"));
        ftc_class_thresh_mult = new QSpinBox(LargeMoleculesFTC);
        ftc_class_thresh_mult->setObjectName(QStringLiteral("ftc_class_thresh_mult"));
        QSizePolicy sizePolicy7(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(ftc_class_thresh_mult->sizePolicy().hasHeightForWidth());
        ftc_class_thresh_mult->setSizePolicy(sizePolicy7);
        ftc_class_thresh_mult->setMaximum(9);

        hboxLayout4->addWidget(ftc_class_thresh_mult);

        label_100 = new QLabel(LargeMoleculesFTC);
        label_100->setObjectName(QStringLiteral("label_100"));

        hboxLayout4->addWidget(label_100);

        ftc_class_thresh_order = new QSpinBox(LargeMoleculesFTC);
        ftc_class_thresh_order->setObjectName(QStringLiteral("ftc_class_thresh_order"));
        sizePolicy7.setHeightForWidth(ftc_class_thresh_order->sizePolicy().hasHeightForWidth());
        ftc_class_thresh_order->setSizePolicy(sizePolicy7);
        ftc_class_thresh_order->setMaximum(9);

        hboxLayout4->addWidget(ftc_class_thresh_order);

        spacerItem8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout4->addItem(spacerItem8);


        vboxLayout2->addLayout(hboxLayout4);

        spacerItem9 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vboxLayout2->addItem(spacerItem9);

        largeMoleculesStack->addWidget(LargeMoleculesFTC);
        LargeMoleculesCASE = new QWidget();
        LargeMoleculesCASE->setObjectName(QStringLiteral("LargeMoleculesCASE"));
        vboxLayout3 = new QVBoxLayout(LargeMoleculesCASE);
        vboxLayout3->setObjectName(QStringLiteral("vboxLayout3"));
        spacerItem10 = new QSpacerItem(20, 100, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vboxLayout3->addItem(spacerItem10);

        largeMoleculesStack->addWidget(LargeMoleculesCASE);
        LargeMoleculesRI = new QWidget();
        LargeMoleculesRI->setObjectName(QStringLiteral("LargeMoleculesRI"));
        verticalLayout_15 = new QVBoxLayout(LargeMoleculesRI);
        verticalLayout_15->setObjectName(QStringLiteral("verticalLayout_15"));
        gridLayout_12 = new QGridLayout();
        gridLayout_12->setObjectName(QStringLiteral("gridLayout_12"));
        ari_r0 = new QSpinBox(LargeMoleculesRI);
        ari_r0->setObjectName(QStringLiteral("ari_r0"));

        gridLayout_12->addWidget(ari_r0, 1, 2, 1, 1);

        checkBox_3 = new QCheckBox(LargeMoleculesRI);
        checkBox_3->setObjectName(QStringLiteral("checkBox_3"));

        gridLayout_12->addWidget(checkBox_3, 1, 0, 1, 1);

        label_77 = new QLabel(LargeMoleculesRI);
        label_77->setObjectName(QStringLiteral("label_77"));

        gridLayout_12->addWidget(label_77, 2, 1, 1, 1);

        ari_r1 = new QSpinBox(LargeMoleculesRI);
        ari_r1->setObjectName(QStringLiteral("ari_r1"));

        gridLayout_12->addWidget(ari_r1, 2, 2, 1, 1);

        checkBox_2 = new QCheckBox(LargeMoleculesRI);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));

        gridLayout_12->addWidget(checkBox_2, 0, 1, 1, 1);

        label_55 = new QLabel(LargeMoleculesRI);
        label_55->setObjectName(QStringLiteral("label_55"));

        gridLayout_12->addWidget(label_55, 1, 1, 1, 1);

        checkBox = new QCheckBox(LargeMoleculesRI);
        checkBox->setObjectName(QStringLiteral("checkBox"));

        gridLayout_12->addWidget(checkBox, 0, 0, 1, 1);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_12->addItem(horizontalSpacer_13, 2, 3, 1, 1);


        verticalLayout_15->addLayout(gridLayout_12);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_15->addItem(verticalSpacer_5);

        largeMoleculesStack->addWidget(LargeMoleculesRI);

        verticalLayout_16->addWidget(largeMoleculesStack);

        verticalSpacer_11 = new QSpacerItem(20, 280, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_16->addItem(verticalSpacer_11);

        advancedOptionsStack->addWidget(AdvancedLargeMoleculeMethods);
        AdvancedHFPT = new QWidget();
        AdvancedHFPT->setObjectName(QStringLiteral("AdvancedHFPT"));
        verticalLayout_13 = new QVBoxLayout(AdvancedHFPT);
        verticalLayout_13->setObjectName(QStringLiteral("verticalLayout_13"));
        gridLayout_21 = new QGridLayout();
        gridLayout_21->setObjectName(QStringLiteral("gridLayout_21"));
        label_3 = new QLabel(AdvancedHFPT);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_21->addWidget(label_3, 0, 0, 1, 1);

        label_dfpt_xc_grid = new QLabel(AdvancedHFPT);
        label_dfpt_xc_grid->setObjectName(QStringLiteral("label_dfpt_xc_grid"));

        gridLayout_21->addWidget(label_dfpt_xc_grid, 1, 0, 1, 1);

        dfpt_exchange = new QComboBox(AdvancedHFPT);
        dfpt_exchange->setObjectName(QStringLiteral("dfpt_exchange"));
        dfpt_exchange->setEditable(true);

        gridLayout_21->addWidget(dfpt_exchange, 2, 1, 1, 1);

        dfpt_xc_grid = new QComboBox(AdvancedHFPT);
        dfpt_xc_grid->setObjectName(QStringLiteral("dfpt_xc_grid"));
        dfpt_xc_grid->setEditable(true);

        gridLayout_21->addWidget(dfpt_xc_grid, 1, 1, 1, 1);

        hfpt_basis = new QComboBox(AdvancedHFPT);
        hfpt_basis->setObjectName(QStringLiteral("hfpt_basis"));
        hfpt_basis->setEditable(true);

        gridLayout_21->addWidget(hfpt_basis, 0, 1, 1, 1);

        label_dfpt_exchange = new QLabel(AdvancedHFPT);
        label_dfpt_exchange->setObjectName(QStringLiteral("label_dfpt_exchange"));

        gridLayout_21->addWidget(label_dfpt_exchange, 2, 0, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_21->addItem(horizontalSpacer_7, 0, 2, 1, 1);


        verticalLayout_13->addLayout(gridLayout_21);

        verticalSpacer_29 = new QSpacerItem(20, 534, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_13->addItem(verticalSpacer_29);

        advancedOptionsStack->addWidget(AdvancedHFPT);
        AdvancedPAO = new QWidget();
        AdvancedPAO->setObjectName(QStringLiteral("AdvancedPAO"));
        vboxLayout4 = new QVBoxLayout(AdvancedPAO);
        vboxLayout4->setObjectName(QStringLiteral("vboxLayout4"));
        gridLayout3 = new QGridLayout();
        gridLayout3->setObjectName(QStringLiteral("gridLayout3"));
        label_49 = new QLabel(AdvancedPAO);
        label_49->setObjectName(QStringLiteral("label_49"));

        gridLayout3->addWidget(label_49, 2, 0, 1, 1);

        epao_weights = new QComboBox(AdvancedPAO);
        epao_weights->setObjectName(QStringLiteral("epao_weights"));

        gridLayout3->addWidget(epao_weights, 2, 1, 1, 1);

        label_50 = new QLabel(AdvancedPAO);
        label_50->setObjectName(QStringLiteral("label_50"));

        gridLayout3->addWidget(label_50, 1, 0, 1, 1);

        pao_method = new QComboBox(AdvancedPAO);
        pao_method->setObjectName(QStringLiteral("pao_method"));

        gridLayout3->addWidget(pao_method, 0, 1, 1, 1);

        pao_algorithm = new QComboBox(AdvancedPAO);
        pao_algorithm->setObjectName(QStringLiteral("pao_algorithm"));

        gridLayout3->addWidget(pao_algorithm, 1, 1, 1, 1);

        hboxLayout5 = new QHBoxLayout();
        hboxLayout5->setObjectName(QStringLiteral("hboxLayout5"));
        epao_iterate = new QSpinBox(AdvancedPAO);
        epao_iterate->setObjectName(QStringLiteral("epao_iterate"));

        hboxLayout5->addWidget(epao_iterate);

        spacerItem11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout5->addItem(spacerItem11);


        gridLayout3->addLayout(hboxLayout5, 3, 1, 1, 2);

        label_48 = new QLabel(AdvancedPAO);
        label_48->setObjectName(QStringLiteral("label_48"));

        gridLayout3->addWidget(label_48, 3, 0, 1, 1);

        label_51 = new QLabel(AdvancedPAO);
        label_51->setObjectName(QStringLiteral("label_51"));

        gridLayout3->addWidget(label_51, 0, 0, 1, 1);

        spacerItem12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout3->addItem(spacerItem12, 0, 2, 1, 1);


        vboxLayout4->addLayout(gridLayout3);

        spacerItem13 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vboxLayout4->addItem(spacerItem13);

        advancedOptionsStack->addWidget(AdvancedPAO);
        AdvancedInternalStability = new QWidget();
        AdvancedInternalStability->setObjectName(QStringLiteral("AdvancedInternalStability"));
        verticalLayout_6 = new QVBoxLayout(AdvancedInternalStability);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        gridLayout_7 = new QGridLayout();
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        internal_stability_conv = new QSpinBox(AdvancedInternalStability);
        internal_stability_conv->setObjectName(QStringLiteral("internal_stability_conv"));

        gridLayout_7->addWidget(internal_stability_conv, 2, 1, 1, 1);

        label_67 = new QLabel(AdvancedInternalStability);
        label_67->setObjectName(QStringLiteral("label_67"));

        gridLayout_7->addWidget(label_67, 2, 0, 1, 1);

        internal_stability_roots = new QSpinBox(AdvancedInternalStability);
        internal_stability_roots->setObjectName(QStringLiteral("internal_stability_roots"));

        gridLayout_7->addWidget(internal_stability_roots, 3, 1, 1, 1);

        label_61 = new QLabel(AdvancedInternalStability);
        label_61->setObjectName(QStringLiteral("label_61"));

        gridLayout_7->addWidget(label_61, 1, 0, 1, 1);

        internal_stability_iter = new QSpinBox(AdvancedInternalStability);
        internal_stability_iter->setObjectName(QStringLiteral("internal_stability_iter"));

        gridLayout_7->addWidget(internal_stability_iter, 0, 1, 1, 1);

        label_57 = new QLabel(AdvancedInternalStability);
        label_57->setObjectName(QStringLiteral("label_57"));

        gridLayout_7->addWidget(label_57, 0, 0, 1, 1);

        internal_stability_davidson_iter = new QSpinBox(AdvancedInternalStability);
        internal_stability_davidson_iter->setObjectName(QStringLiteral("internal_stability_davidson_iter"));

        gridLayout_7->addWidget(internal_stability_davidson_iter, 1, 1, 1, 1);

        label_69 = new QLabel(AdvancedInternalStability);
        label_69->setObjectName(QStringLiteral("label_69"));

        gridLayout_7->addWidget(label_69, 3, 0, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_7->addItem(horizontalSpacer_5, 0, 2, 1, 1);

        fd_mat_vec_prod = new QRadioButton(AdvancedInternalStability);
        fd_mat_vec_prod->setObjectName(QStringLiteral("fd_mat_vec_prod"));

        gridLayout_7->addWidget(fd_mat_vec_prod, 4, 0, 1, 3);


        verticalLayout_6->addLayout(gridLayout_7);

        verticalSpacer_4 = new QSpacerItem(20, 394, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer_4);

        advancedOptionsStack->addWidget(AdvancedInternalStability);
        AdvancedThresholds = new QWidget();
        AdvancedThresholds->setObjectName(QStringLiteral("AdvancedThresholds"));
        vboxLayout5 = new QVBoxLayout(AdvancedThresholds);
        vboxLayout5->setObjectName(QStringLiteral("vboxLayout5"));
        gridLayout4 = new QGridLayout();
        gridLayout4->setObjectName(QStringLiteral("gridLayout4"));
        label_32 = new QLabel(AdvancedThresholds);
        label_32->setObjectName(QStringLiteral("label_32"));

        gridLayout4->addWidget(label_32, 2, 0, 1, 1);

        basis_linear_dependence_thresh = new QSpinBox(AdvancedThresholds);
        basis_linear_dependence_thresh->setObjectName(QStringLiteral("basis_linear_dependence_thresh"));

        gridLayout4->addWidget(basis_linear_dependence_thresh, 2, 1, 1, 1);

        thresh = new QSpinBox(AdvancedThresholds);
        thresh->setObjectName(QStringLiteral("thresh"));

        gridLayout4->addWidget(thresh, 0, 1, 1, 1);

        label_40 = new QLabel(AdvancedThresholds);
        label_40->setObjectName(QStringLiteral("label_40"));

        gridLayout4->addWidget(label_40, 0, 0, 1, 1);

        spacerItem14 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout4->addItem(spacerItem14, 0, 2, 1, 1);

        label_211 = new QLabel(AdvancedThresholds);
        label_211->setObjectName(QStringLiteral("label_211"));

        gridLayout4->addWidget(label_211, 3, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        meteco = new QComboBox(AdvancedThresholds);
        meteco->setObjectName(QStringLiteral("meteco"));

        horizontalLayout_2->addWidget(meteco);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        gridLayout4->addLayout(horizontalLayout_2, 4, 0, 1, 3);

        label_198 = new QLabel(AdvancedThresholds);
        label_198->setObjectName(QStringLiteral("label_198"));

        gridLayout4->addWidget(label_198, 1, 0, 1, 1);

        varthresh = new QSpinBox(AdvancedThresholds);
        varthresh->setObjectName(QStringLiteral("varthresh"));

        gridLayout4->addWidget(varthresh, 1, 1, 1, 1);


        vboxLayout5->addLayout(gridLayout4);

        spacerItem15 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vboxLayout5->addItem(spacerItem15);

        advancedOptionsStack->addWidget(AdvancedThresholds);
        AdvancedDFT = new QWidget();
        AdvancedDFT->setObjectName(QStringLiteral("AdvancedDFT"));
        verticalLayout_49 = new QVBoxLayout(AdvancedDFT);
        verticalLayout_49->setObjectName(QStringLiteral("verticalLayout_49"));
        horizontalLayout_32 = new QHBoxLayout();
        horizontalLayout_32->setObjectName(QStringLiteral("horizontalLayout_32"));
        label_2 = new QLabel(AdvancedDFT);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_32->addWidget(label_2);

        xc_grid = new QComboBox(AdvancedDFT);
        xc_grid->setObjectName(QStringLiteral("xc_grid"));
        xc_grid->setEditable(true);

        horizontalLayout_32->addWidget(xc_grid);

        horizontalSpacer_33 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_32->addItem(horizontalSpacer_33);


        verticalLayout_49->addLayout(horizontalLayout_32);

        xc_smart_grid = new QCheckBox(AdvancedDFT);
        xc_smart_grid->setObjectName(QStringLiteral("xc_smart_grid"));

        verticalLayout_49->addWidget(xc_smart_grid);

        fast_xc = new QCheckBox(AdvancedDFT);
        fast_xc->setObjectName(QStringLiteral("fast_xc"));

        verticalLayout_49->addWidget(fast_xc);

        incdft = new QCheckBox(AdvancedDFT);
        incdft->setObjectName(QStringLiteral("incdft"));

        verticalLayout_49->addWidget(incdft);

        mrxc = new QCheckBox(AdvancedDFT);
        mrxc->setObjectName(QStringLiteral("mrxc"));

        verticalLayout_49->addWidget(mrxc);

        groupBox_mrxc = new QGroupBox(AdvancedDFT);
        groupBox_mrxc->setObjectName(QStringLiteral("groupBox_mrxc"));
        verticalLayout_48 = new QVBoxLayout(groupBox_mrxc);
        verticalLayout_48->setObjectName(QStringLiteral("verticalLayout_48"));
        label_8 = new QLabel(groupBox_mrxc);
        label_8->setObjectName(QStringLiteral("label_8"));

        verticalLayout_48->addWidget(label_8);

        _5 = new QHBoxLayout();
        _5->setObjectName(QStringLiteral("_5"));
        mrxc_class_thresh_mult = new QSpinBox(groupBox_mrxc);
        mrxc_class_thresh_mult->setObjectName(QStringLiteral("mrxc_class_thresh_mult"));
        sizePolicy7.setHeightForWidth(mrxc_class_thresh_mult->sizePolicy().hasHeightForWidth());
        mrxc_class_thresh_mult->setSizePolicy(sizePolicy7);
        mrxc_class_thresh_mult->setMaximum(9);

        _5->addWidget(mrxc_class_thresh_mult);

        label_102 = new QLabel(groupBox_mrxc);
        label_102->setObjectName(QStringLiteral("label_102"));

        _5->addWidget(label_102);

        mrxc_class_thresh_order = new QSpinBox(groupBox_mrxc);
        mrxc_class_thresh_order->setObjectName(QStringLiteral("mrxc_class_thresh_order"));
        sizePolicy7.setHeightForWidth(mrxc_class_thresh_order->sizePolicy().hasHeightForWidth());
        mrxc_class_thresh_order->setSizePolicy(sizePolicy7);
        mrxc_class_thresh_order->setMaximum(9);

        _5->addWidget(mrxc_class_thresh_order);

        spacerItem16 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        _5->addItem(spacerItem16);


        verticalLayout_48->addLayout(_5);

        horizontalLayout_34 = new QHBoxLayout();
        horizontalLayout_34->setObjectName(QStringLiteral("horizontalLayout_34"));
        label_7 = new QLabel(groupBox_mrxc);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_34->addWidget(label_7);

        local_interp_order = new QSpinBox(groupBox_mrxc);
        local_interp_order->setObjectName(QStringLiteral("local_interp_order"));

        horizontalLayout_34->addWidget(local_interp_order);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_34->addItem(horizontalSpacer_6);


        verticalLayout_48->addLayout(horizontalLayout_34);


        verticalLayout_49->addWidget(groupBox_mrxc);

        spacerItem17 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_49->addItem(spacerItem17);

        advancedOptionsStack->addWidget(AdvancedDFT);
        AdvancedDispersionCorrection = new QWidget();
        AdvancedDispersionCorrection->setObjectName(QStringLiteral("AdvancedDispersionCorrection"));
        verticalLayout_39 = new QVBoxLayout(AdvancedDispersionCorrection);
        verticalLayout_39->setObjectName(QStringLiteral("verticalLayout_39"));
        gridLayout_14 = new QGridLayout();
        gridLayout_14->setObjectName(QStringLiteral("gridLayout_14"));
        label_76 = new QLabel(AdvancedDispersionCorrection);
        label_76->setObjectName(QStringLiteral("label_76"));

        gridLayout_14->addWidget(label_76, 0, 0, 1, 1);

        label_98 = new QLabel(AdvancedDispersionCorrection);
        label_98->setObjectName(QStringLiteral("label_98"));

        gridLayout_14->addWidget(label_98, 1, 0, 1, 1);

        dft_d = new QComboBox(AdvancedDispersionCorrection);
        dft_d->setObjectName(QStringLiteral("dft_d"));

        gridLayout_14->addWidget(dft_d, 0, 1, 1, 1);

        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setObjectName(QStringLiteral("horizontalLayout_19"));
        dft_d_a = new QDoubleSpinBox(AdvancedDispersionCorrection);
        dft_d_a->setObjectName(QStringLiteral("dft_d_a"));
        dft_d_a->setSingleStep(0.01);

        horizontalLayout_19->addWidget(dft_d_a);

        spacerItem18 = new QSpacerItem(47, 26, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_19->addItem(spacerItem18);


        gridLayout_14->addLayout(horizontalLayout_19, 1, 1, 1, 1);


        verticalLayout_39->addLayout(gridLayout_14);

        groupBox_dft_d = new QGroupBox(AdvancedDispersionCorrection);
        groupBox_dft_d->setObjectName(QStringLiteral("groupBox_dft_d"));
        gridLayout_17 = new QGridLayout(groupBox_dft_d);
        gridLayout_17->setObjectName(QStringLiteral("gridLayout_17"));
        label_9 = new QLabel(groupBox_dft_d);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setTextFormat(Qt::RichText);

        gridLayout_17->addWidget(label_9, 0, 0, 1, 1);

        label_19 = new QLabel(groupBox_dft_d);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setTextFormat(Qt::RichText);

        gridLayout_17->addWidget(label_19, 1, 0, 1, 1);

        label_20 = new QLabel(groupBox_dft_d);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setTextFormat(Qt::RichText);

        gridLayout_17->addWidget(label_20, 2, 0, 1, 1);

        dft_d3_3body = new QCheckBox(groupBox_dft_d);
        dft_d3_3body->setObjectName(QStringLiteral("dft_d3_3body"));

        gridLayout_17->addWidget(dft_d3_3body, 3, 0, 1, 4);

        horizontalSpacer_34 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_17->addItem(horizontalSpacer_34, 0, 2, 1, 1);

        dft_d3_s6 = new QDoubleSpinBox(groupBox_dft_d);
        dft_d3_s6->setObjectName(QStringLiteral("dft_d3_s6"));
        dft_d3_s6->setDecimals(3);

        gridLayout_17->addWidget(dft_d3_s6, 0, 1, 1, 1);

        dft_d3_sr6 = new QDoubleSpinBox(groupBox_dft_d);
        dft_d3_sr6->setObjectName(QStringLiteral("dft_d3_sr6"));
        dft_d3_sr6->setDecimals(3);

        gridLayout_17->addWidget(dft_d3_sr6, 1, 1, 1, 1);

        dft_d3_s8 = new QDoubleSpinBox(groupBox_dft_d);
        dft_d3_s8->setObjectName(QStringLiteral("dft_d3_s8"));
        dft_d3_s8->setDecimals(3);

        gridLayout_17->addWidget(dft_d3_s8, 2, 1, 1, 1);


        verticalLayout_39->addWidget(groupBox_dft_d);

        verticalSpacer_20 = new QSpacerItem(20, 306, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_39->addItem(verticalSpacer_20);

        advancedOptionsStack->addWidget(AdvancedDispersionCorrection);
        AdvancedXDM = new QWidget();
        AdvancedXDM->setObjectName(QStringLiteral("AdvancedXDM"));
        verticalLayout_46 = new QVBoxLayout(AdvancedXDM);
        verticalLayout_46->setObjectName(QStringLiteral("verticalLayout_46"));
        gridLayout_15 = new QGridLayout();
        gridLayout_15->setObjectName(QStringLiteral("gridLayout_15"));
        label = new QLabel(AdvancedXDM);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_15->addWidget(label, 0, 0, 1, 1);

        dftvdw_jobnumber = new QComboBox(AdvancedXDM);
        dftvdw_jobnumber->setObjectName(QStringLiteral("dftvdw_jobnumber"));

        gridLayout_15->addWidget(dftvdw_jobnumber, 0, 1, 1, 1);

        label_dftvdw_method = new QLabel(AdvancedXDM);
        label_dftvdw_method->setObjectName(QStringLiteral("label_dftvdw_method"));

        gridLayout_15->addWidget(label_dftvdw_method, 1, 0, 1, 1);

        dftvdw_method = new QComboBox(AdvancedXDM);
        dftvdw_method->setObjectName(QStringLiteral("dftvdw_method"));

        gridLayout_15->addWidget(dftvdw_method, 1, 1, 1, 1);

        label_dftvdw_print = new QLabel(AdvancedXDM);
        label_dftvdw_print->setObjectName(QStringLiteral("label_dftvdw_print"));

        gridLayout_15->addWidget(label_dftvdw_print, 2, 0, 1, 1);

        dftvdw_print = new QComboBox(AdvancedXDM);
        dftvdw_print->setObjectName(QStringLiteral("dftvdw_print"));

        gridLayout_15->addWidget(dftvdw_print, 2, 1, 1, 1);

        horizontalLayout_28 = new QHBoxLayout();
        horizontalLayout_28->setObjectName(QStringLiteral("horizontalLayout_28"));
        dftvdw_mol1natoms = new QSpinBox(AdvancedXDM);
        dftvdw_mol1natoms->setObjectName(QStringLiteral("dftvdw_mol1natoms"));

        horizontalLayout_28->addWidget(dftvdw_mol1natoms);

        horizontalSpacer_28 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_28->addItem(horizontalSpacer_28);


        gridLayout_15->addLayout(horizontalLayout_28, 3, 1, 1, 1);

        label_dftvdw_mol1natoms = new QLabel(AdvancedXDM);
        label_dftvdw_mol1natoms->setObjectName(QStringLiteral("label_dftvdw_mol1natoms"));

        gridLayout_15->addWidget(label_dftvdw_mol1natoms, 3, 0, 1, 1);

        label_dftvdw_kai = new QLabel(AdvancedXDM);
        label_dftvdw_kai->setObjectName(QStringLiteral("label_dftvdw_kai"));

        gridLayout_15->addWidget(label_dftvdw_kai, 4, 0, 1, 1);

        horizontalLayout_29 = new QHBoxLayout();
        horizontalLayout_29->setObjectName(QStringLiteral("horizontalLayout_29"));
        dftvdw_kai = new QSpinBox(AdvancedXDM);
        dftvdw_kai->setObjectName(QStringLiteral("dftvdw_kai"));

        horizontalLayout_29->addWidget(dftvdw_kai);

        horizontalSpacer_29 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_29->addItem(horizontalSpacer_29);


        gridLayout_15->addLayout(horizontalLayout_29, 4, 1, 1, 1);

        label_dftvdw_alpha1 = new QLabel(AdvancedXDM);
        label_dftvdw_alpha1->setObjectName(QStringLiteral("label_dftvdw_alpha1"));
        label_dftvdw_alpha1->setEnabled(true);
        label_dftvdw_alpha1->setTextFormat(Qt::RichText);

        gridLayout_15->addWidget(label_dftvdw_alpha1, 5, 0, 1, 1);

        label_dftvdw_alpha2 = new QLabel(AdvancedXDM);
        label_dftvdw_alpha2->setObjectName(QStringLiteral("label_dftvdw_alpha2"));
        label_dftvdw_alpha2->setEnabled(true);
        label_dftvdw_alpha2->setTextFormat(Qt::RichText);

        gridLayout_15->addWidget(label_dftvdw_alpha2, 6, 0, 1, 1);

        horizontalLayout_30 = new QHBoxLayout();
        horizontalLayout_30->setObjectName(QStringLiteral("horizontalLayout_30"));
        dftvdw_alpha1 = new QSpinBox(AdvancedXDM);
        dftvdw_alpha1->setObjectName(QStringLiteral("dftvdw_alpha1"));
        dftvdw_alpha1->setEnabled(true);

        horizontalLayout_30->addWidget(dftvdw_alpha1);

        horizontalSpacer_30 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_30->addItem(horizontalSpacer_30);


        gridLayout_15->addLayout(horizontalLayout_30, 5, 1, 1, 1);

        horizontalLayout_31 = new QHBoxLayout();
        horizontalLayout_31->setObjectName(QStringLiteral("horizontalLayout_31"));
        dftvdw_alpha2 = new QSpinBox(AdvancedXDM);
        dftvdw_alpha2->setObjectName(QStringLiteral("dftvdw_alpha2"));
        dftvdw_alpha2->setEnabled(true);

        horizontalLayout_31->addWidget(dftvdw_alpha2);

        horizontalSpacer_31 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_31->addItem(horizontalSpacer_31);


        gridLayout_15->addLayout(horizontalLayout_31, 6, 1, 1, 1);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_15->addItem(horizontalSpacer_9, 0, 2, 1, 1);


        verticalLayout_46->addLayout(gridLayout_15);

        verticalSpacer_26 = new QSpacerItem(20, 311, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_46->addItem(verticalSpacer_26);

        advancedOptionsStack->addWidget(AdvancedXDM);
        AdvancedNonlocalCorrelation = new QWidget();
        AdvancedNonlocalCorrelation->setObjectName(QStringLiteral("AdvancedNonlocalCorrelation"));
        verticalLayout_47 = new QVBoxLayout(AdvancedNonlocalCorrelation);
        verticalLayout_47->setObjectName(QStringLiteral("verticalLayout_47"));
        gridLayout_16 = new QGridLayout();
        gridLayout_16->setObjectName(QStringLiteral("gridLayout_16"));
        label_6 = new QLabel(AdvancedNonlocalCorrelation);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout_16->addWidget(label_6, 1, 0, 1, 1);

        label_4 = new QLabel(AdvancedNonlocalCorrelation);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_16->addWidget(label_4, 0, 0, 1, 1);

        nl_correlation = new QComboBox(AdvancedNonlocalCorrelation);
        nl_correlation->setObjectName(QStringLiteral("nl_correlation"));

        gridLayout_16->addWidget(nl_correlation, 0, 1, 1, 1);

        nl_grid = new QComboBox(AdvancedNonlocalCorrelation);
        nl_grid->setObjectName(QStringLiteral("nl_grid"));
        nl_grid->setEditable(true);

        gridLayout_16->addWidget(nl_grid, 1, 1, 1, 1);

        horizontalSpacer_35 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_16->addItem(horizontalSpacer_35, 0, 2, 1, 1);


        verticalLayout_47->addLayout(gridLayout_16);

        verticalSpacer_27 = new QSpacerItem(20, 529, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_47->addItem(verticalSpacer_27);

        advancedOptionsStack->addWidget(AdvancedNonlocalCorrelation);
        AdvancedPostHartreeFock = new QWidget();
        AdvancedPostHartreeFock->setObjectName(QStringLiteral("AdvancedPostHartreeFock"));
        verticalLayout_19 = new QVBoxLayout(AdvancedPostHartreeFock);
        verticalLayout_19->setObjectName(QStringLiteral("verticalLayout_19"));
        groupBox_3 = new QGroupBox(AdvancedPostHartreeFock);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        verticalLayout_17 = new QVBoxLayout(groupBox_3);
        verticalLayout_17->setObjectName(QStringLiteral("verticalLayout_17"));
        qui_frozen_core = new QCheckBox(groupBox_3);
        qui_frozen_core->setObjectName(QStringLiteral("qui_frozen_core"));

        verticalLayout_17->addWidget(qui_frozen_core);

        gridLayout5 = new QGridLayout();
        gridLayout5->setObjectName(QStringLiteral("gridLayout5"));
        label_93 = new QLabel(groupBox_3);
        label_93->setObjectName(QStringLiteral("label_93"));

        gridLayout5->addWidget(label_93, 3, 0, 1, 1);

        core_character_print = new QComboBox(groupBox_3);
        core_character_print->setObjectName(QStringLiteral("core_character_print"));

        gridLayout5->addWidget(core_character_print, 3, 1, 1, 2);

        core_character = new QSpinBox(groupBox_3);
        core_character->setObjectName(QStringLiteral("core_character"));

        gridLayout5->addWidget(core_character, 2, 2, 1, 1);

        n_frozen_virtual = new QSpinBox(groupBox_3);
        n_frozen_virtual->setObjectName(QStringLiteral("n_frozen_virtual"));

        gridLayout5->addWidget(n_frozen_virtual, 1, 2, 1, 1);

        n_frozen_core = new QSpinBox(groupBox_3);
        n_frozen_core->setObjectName(QStringLiteral("n_frozen_core"));

        gridLayout5->addWidget(n_frozen_core, 0, 2, 1, 1);

        label_234 = new QLabel(groupBox_3);
        label_234->setObjectName(QStringLiteral("label_234"));

        gridLayout5->addWidget(label_234, 1, 0, 1, 2);

        label_123 = new QLabel(groupBox_3);
        label_123->setObjectName(QStringLiteral("label_123"));

        gridLayout5->addWidget(label_123, 0, 0, 1, 2);

        label_92 = new QLabel(groupBox_3);
        label_92->setObjectName(QStringLiteral("label_92"));

        gridLayout5->addWidget(label_92, 2, 0, 1, 2);


        verticalLayout_17->addLayout(gridLayout5);


        verticalLayout_19->addWidget(groupBox_3);

        ssg = new QCheckBox(AdvancedPostHartreeFock);
        ssg->setObjectName(QStringLiteral("ssg"));

        verticalLayout_19->addWidget(ssg);

        mp2v = new QCheckBox(AdvancedPostHartreeFock);
        mp2v->setObjectName(QStringLiteral("mp2v"));

        verticalLayout_19->addWidget(mp2v);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_28 = new QLabel(AdvancedPostHartreeFock);
        label_28->setObjectName(QStringLiteral("label_28"));

        horizontalLayout->addWidget(label_28);

        cd_algorithm = new QComboBox(AdvancedPostHartreeFock);
        cd_algorithm->setObjectName(QStringLiteral("cd_algorithm"));

        horizontalLayout->addWidget(cd_algorithm);


        verticalLayout_19->addLayout(horizontalLayout);

        verticalSpacer_30 = new QSpacerItem(20, 570, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_19->addItem(verticalSpacer_30);

        advancedOptionsStack->addWidget(AdvancedPostHartreeFock);
        AdvancedCoupledCluster = new QWidget();
        AdvancedCoupledCluster->setObjectName(QStringLiteral("AdvancedCoupledCluster"));
        verticalLayout = new QVBoxLayout(AdvancedCoupledCluster);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout_8 = new QGridLayout();
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        label_133 = new QLabel(AdvancedCoupledCluster);
        label_133->setObjectName(QStringLiteral("label_133"));

        gridLayout_8->addWidget(label_133, 7, 0, 1, 1);

        label_224 = new QLabel(AdvancedCoupledCluster);
        label_224->setObjectName(QStringLiteral("label_224"));

        gridLayout_8->addWidget(label_224, 8, 0, 1, 1);

        label_151 = new QLabel(AdvancedCoupledCluster);
        label_151->setObjectName(QStringLiteral("label_151"));

        gridLayout_8->addWidget(label_151, 9, 0, 1, 1);

        label_155 = new QLabel(AdvancedCoupledCluster);
        label_155->setObjectName(QStringLiteral("label_155"));

        gridLayout_8->addWidget(label_155, 10, 0, 1, 1);

        label_152 = new QLabel(AdvancedCoupledCluster);
        label_152->setObjectName(QStringLiteral("label_152"));

        gridLayout_8->addWidget(label_152, 13, 0, 1, 1);

        cc_dov_thresh = new QLineEdit(AdvancedCoupledCluster);
        cc_dov_thresh->setObjectName(QStringLiteral("cc_dov_thresh"));

        gridLayout_8->addWidget(cc_dov_thresh, 13, 1, 1, 2);

        cc_max_iter = new QSpinBox(AdvancedCoupledCluster);
        cc_max_iter->setObjectName(QStringLiteral("cc_max_iter"));

        gridLayout_8->addWidget(cc_max_iter, 7, 1, 1, 1);

        cc_convergence = new QSpinBox(AdvancedCoupledCluster);
        cc_convergence->setObjectName(QStringLiteral("cc_convergence"));

        gridLayout_8->addWidget(cc_convergence, 8, 1, 1, 1);

        cc_diis = new QSpinBox(AdvancedCoupledCluster);
        cc_diis->setObjectName(QStringLiteral("cc_diis"));

        gridLayout_8->addWidget(cc_diis, 9, 1, 1, 1);

        cc_diis_start = new QSpinBox(AdvancedCoupledCluster);
        cc_diis_start->setObjectName(QStringLiteral("cc_diis_start"));

        gridLayout_8->addWidget(cc_diis_start, 10, 1, 1, 1);

        label_227 = new QLabel(AdvancedCoupledCluster);
        label_227->setObjectName(QStringLiteral("label_227"));

        gridLayout_8->addWidget(label_227, 6, 0, 1, 1);

        cc_print = new QSpinBox(AdvancedCoupledCluster);
        cc_print->setObjectName(QStringLiteral("cc_print"));

        gridLayout_8->addWidget(cc_print, 6, 1, 1, 1);

        label_104 = new QLabel(AdvancedCoupledCluster);
        label_104->setObjectName(QStringLiteral("label_104"));

        gridLayout_8->addWidget(label_104, 11, 0, 1, 1);

        cholesky_tol = new QSpinBox(AdvancedCoupledCluster);
        cholesky_tol->setObjectName(QStringLiteral("cholesky_tol"));

        gridLayout_8->addWidget(cholesky_tol, 11, 1, 1, 1);

        ccman2 = new QCheckBox(AdvancedCoupledCluster);
        ccman2->setObjectName(QStringLiteral("ccman2"));

        gridLayout_8->addWidget(ccman2, 0, 0, 1, 1);

        cc_ref_prop = new QCheckBox(AdvancedCoupledCluster);
        cc_ref_prop->setObjectName(QStringLiteral("cc_ref_prop"));

        gridLayout_8->addWidget(cc_ref_prop, 1, 0, 1, 2);

        cc_ref_prop_te = new QCheckBox(AdvancedCoupledCluster);
        cc_ref_prop_te->setObjectName(QStringLiteral("cc_ref_prop_te"));

        gridLayout_8->addWidget(cc_ref_prop_te, 2, 0, 1, 2);

        cc_fullresponse = new QCheckBox(AdvancedCoupledCluster);
        cc_fullresponse->setObjectName(QStringLiteral("cc_fullresponse"));

        gridLayout_8->addWidget(cc_fullresponse, 3, 0, 1, 2);

        spacerItem19 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_8->addItem(spacerItem19, 6, 2, 1, 1);

        direct_ri = new QCheckBox(AdvancedCoupledCluster);
        direct_ri->setObjectName(QStringLiteral("direct_ri"));

        gridLayout_8->addWidget(direct_ri, 12, 0, 1, 1);

        label_226 = new QLabel(AdvancedCoupledCluster);
        label_226->setObjectName(QStringLiteral("label_226"));

        gridLayout_8->addWidget(label_226, 4, 0, 1, 1);

        cc_memory = new QSpinBox(AdvancedCoupledCluster);
        cc_memory->setObjectName(QStringLiteral("cc_memory"));

        gridLayout_8->addWidget(cc_memory, 4, 1, 1, 1);

        label_115 = new QLabel(AdvancedCoupledCluster);
        label_115->setObjectName(QStringLiteral("label_115"));

        gridLayout_8->addWidget(label_115, 5, 0, 1, 1);

        threads = new QSpinBox(AdvancedCoupledCluster);
        threads->setObjectName(QStringLiteral("threads"));
        threads->setMaximum(10000);

        gridLayout_8->addWidget(threads, 5, 1, 1, 1);

        cc_symmetry = new QCheckBox(AdvancedCoupledCluster);
        cc_symmetry->setObjectName(QStringLiteral("cc_symmetry"));

        gridLayout_8->addWidget(cc_symmetry, 0, 1, 1, 2);


        verticalLayout->addLayout(gridLayout_8);

        verticalSpacer_7 = new QSpacerItem(20, 346, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_7);

        advancedOptionsStack->addWidget(AdvancedCoupledCluster);
        AdvancedCIS = new QWidget();
        AdvancedCIS->setObjectName(QStringLiteral("AdvancedCIS"));
        verticalLayout_11 = new QVBoxLayout(AdvancedCIS);
        verticalLayout_11->setObjectName(QStringLiteral("verticalLayout_11"));
        groupBox_2 = new QGroupBox(AdvancedCIS);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        verticalLayout_9 = new QVBoxLayout(groupBox_2);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        gridLayout6 = new QGridLayout();
        gridLayout6->setObjectName(QStringLiteral("gridLayout6"));
        cis_convergence = new QSpinBox(groupBox_2);
        cis_convergence->setObjectName(QStringLiteral("cis_convergence"));

        gridLayout6->addWidget(cis_convergence, 1, 1, 1, 1);

        max_cis_subspace = new QSpinBox(groupBox_2);
        max_cis_subspace->setObjectName(QStringLiteral("max_cis_subspace"));

        gridLayout6->addWidget(max_cis_subspace, 2, 1, 1, 1);

        label_166 = new QLabel(groupBox_2);
        label_166->setObjectName(QStringLiteral("label_166"));

        gridLayout6->addWidget(label_166, 0, 0, 1, 1);

        label_22 = new QLabel(groupBox_2);
        label_22->setObjectName(QStringLiteral("label_22"));

        gridLayout6->addWidget(label_22, 2, 0, 1, 1);

        cis_max_cycles = new QSpinBox(groupBox_2);
        cis_max_cycles->setObjectName(QStringLiteral("cis_max_cycles"));

        gridLayout6->addWidget(cis_max_cycles, 0, 1, 1, 1);

        spacerItem20 = new QSpacerItem(10, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout6->addItem(spacerItem20, 0, 2, 1, 1);

        label_66 = new QLabel(groupBox_2);
        label_66->setObjectName(QStringLiteral("label_66"));

        gridLayout6->addWidget(label_66, 1, 0, 1, 1);

        label_90 = new QLabel(groupBox_2);
        label_90->setObjectName(QStringLiteral("label_90"));

        gridLayout6->addWidget(label_90, 3, 0, 1, 1);

        qui_cis_guess = new QComboBox(groupBox_2);
        qui_cis_guess->setObjectName(QStringLiteral("qui_cis_guess"));

        gridLayout6->addWidget(qui_cis_guess, 3, 1, 1, 2);


        verticalLayout_9->addLayout(gridLayout6);

        cis_dynamic_mem = new QCheckBox(groupBox_2);
        cis_dynamic_mem->setObjectName(QStringLiteral("cis_dynamic_mem"));

        verticalLayout_9->addWidget(cis_dynamic_mem);


        verticalLayout_11->addWidget(groupBox_2);

        groupBox_10 = new QGroupBox(AdvancedCIS);
        groupBox_10->setObjectName(QStringLiteral("groupBox_10"));
        verticalLayout_14 = new QVBoxLayout(groupBox_10);
        verticalLayout_14->setObjectName(QStringLiteral("verticalLayout_14"));
        gridLayout_22 = new QGridLayout();
        gridLayout_22->setObjectName(QStringLiteral("gridLayout_22"));
        label_cis_ras_cutoff_virtual = new QLabel(groupBox_10);
        label_cis_ras_cutoff_virtual->setObjectName(QStringLiteral("label_cis_ras_cutoff_virtual"));

        gridLayout_22->addWidget(label_cis_ras_cutoff_virtual, 3, 0, 1, 1);

        label_cis_ras_cutoff_occupied = new QLabel(groupBox_10);
        label_cis_ras_cutoff_occupied->setObjectName(QStringLiteral("label_cis_ras_cutoff_occupied"));

        gridLayout_22->addWidget(label_cis_ras_cutoff_occupied, 2, 0, 1, 1);

        cis_ras_cutoff_occupied = new QDoubleSpinBox(groupBox_10);
        cis_ras_cutoff_occupied->setObjectName(QStringLiteral("cis_ras_cutoff_occupied"));

        gridLayout_22->addWidget(cis_ras_cutoff_occupied, 2, 1, 1, 1);

        label_cis_ras_type = new QLabel(groupBox_10);
        label_cis_ras_type->setObjectName(QStringLiteral("label_cis_ras_type"));

        gridLayout_22->addWidget(label_cis_ras_type, 4, 0, 1, 1);

        cis_ras_cutoff_virtual = new QDoubleSpinBox(groupBox_10);
        cis_ras_cutoff_virtual->setObjectName(QStringLiteral("cis_ras_cutoff_virtual"));

        gridLayout_22->addWidget(cis_ras_cutoff_virtual, 3, 1, 1, 1);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_22->addItem(horizontalSpacer_11, 2, 2, 1, 1);

        cis_ras = new QCheckBox(groupBox_10);
        cis_ras->setObjectName(QStringLiteral("cis_ras"));

        gridLayout_22->addWidget(cis_ras, 0, 0, 1, 3);

        cis_ras_print = new QCheckBox(groupBox_10);
        cis_ras_print->setObjectName(QStringLiteral("cis_ras_print"));

        gridLayout_22->addWidget(cis_ras_print, 1, 0, 1, 3);

        cis_ras_type = new QComboBox(groupBox_10);
        cis_ras_type->setObjectName(QStringLiteral("cis_ras_type"));

        gridLayout_22->addWidget(cis_ras_type, 4, 1, 1, 2);


        verticalLayout_14->addLayout(gridLayout_22);


        verticalLayout_11->addWidget(groupBox_10);

        spacerItem21 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_11->addItem(spacerItem21);

        advancedOptionsStack->addWidget(AdvancedCIS);
        AdvancedROKS = new QWidget();
        AdvancedROKS->setObjectName(QStringLiteral("AdvancedROKS"));
        verticalLayout_21 = new QVBoxLayout(AdvancedROKS);
        verticalLayout_21->setObjectName(QStringLiteral("verticalLayout_21"));
        roks = new QCheckBox(AdvancedROKS);
        roks->setObjectName(QStringLiteral("roks"));

        verticalLayout_21->addWidget(roks);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_27 = new QLabel(AdvancedROKS);
        label_27->setObjectName(QStringLiteral("label_27"));

        horizontalLayout_4->addWidget(label_27);

        roks_level_shift = new QDoubleSpinBox(AdvancedROKS);
        roks_level_shift->setObjectName(QStringLiteral("roks_level_shift"));
        roks_level_shift->setMaximum(9.99);
        roks_level_shift->setSingleStep(0.01);

        horizontalLayout_4->addWidget(roks_level_shift);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_10);


        verticalLayout_21->addLayout(horizontalLayout_4);

        verticalSpacer_32 = new QSpacerItem(20, 575, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_21->addItem(verticalSpacer_32);

        advancedOptionsStack->addWidget(AdvancedROKS);
        AdvancedEOM = new QWidget();
        AdvancedEOM->setObjectName(QStringLiteral("AdvancedEOM"));
        verticalLayout_4 = new QVBoxLayout(AdvancedEOM);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        spacerItem22 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(spacerItem22, 0, 2, 1, 1);

        label_188 = new QLabel(AdvancedEOM);
        label_188->setObjectName(QStringLiteral("label_188"));

        gridLayout_2->addWidget(label_188, 0, 0, 1, 1);

        eom_corr = new QComboBox(AdvancedEOM);
        eom_corr->setObjectName(QStringLiteral("eom_corr"));

        gridLayout_2->addWidget(eom_corr, 0, 1, 1, 1);


        verticalLayout_4->addLayout(gridLayout_2);

        groupBox_17 = new QGroupBox(AdvancedEOM);
        groupBox_17->setObjectName(QStringLiteral("groupBox_17"));
        gridLayout_3 = new QGridLayout(groupBox_17);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        label_195 = new QLabel(groupBox_17);
        label_195->setObjectName(QStringLiteral("label_195"));

        gridLayout_3->addWidget(label_195, 0, 0, 1, 1);

        eom_nguess_singles = new QSpinBox(groupBox_17);
        eom_nguess_singles->setObjectName(QStringLiteral("eom_nguess_singles"));

        gridLayout_3->addWidget(eom_nguess_singles, 0, 1, 1, 1);

        label_196 = new QLabel(groupBox_17);
        label_196->setObjectName(QStringLiteral("label_196"));

        gridLayout_3->addWidget(label_196, 1, 0, 1, 1);

        eom_nguess_doubles = new QSpinBox(groupBox_17);
        eom_nguess_doubles->setObjectName(QStringLiteral("eom_nguess_doubles"));

        gridLayout_3->addWidget(eom_nguess_doubles, 1, 1, 1, 1);


        verticalLayout_4->addWidget(groupBox_17);

        groupBox_14 = new QGroupBox(AdvancedEOM);
        groupBox_14->setObjectName(QStringLiteral("groupBox_14"));
        verticalLayout_2 = new QVBoxLayout(groupBox_14);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        gridLayout_9 = new QGridLayout();
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        label_215 = new QLabel(groupBox_14);
        label_215->setObjectName(QStringLiteral("label_215"));

        gridLayout_9->addWidget(label_215, 0, 0, 1, 1);

        label_162 = new QLabel(groupBox_14);
        label_162->setObjectName(QStringLiteral("label_162"));

        gridLayout_9->addWidget(label_162, 1, 0, 1, 1);

        label_167 = new QLabel(groupBox_14);
        label_167->setObjectName(QStringLiteral("label_167"));

        gridLayout_9->addWidget(label_167, 2, 0, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_9->addItem(horizontalSpacer_8, 0, 2, 1, 1);

        eom_davidson_convergence = new QSpinBox(groupBox_14);
        eom_davidson_convergence->setObjectName(QStringLiteral("eom_davidson_convergence"));

        gridLayout_9->addWidget(eom_davidson_convergence, 0, 1, 1, 1);

        eom_davidson_maxvectors = new QSpinBox(groupBox_14);
        eom_davidson_maxvectors->setObjectName(QStringLiteral("eom_davidson_maxvectors"));

        gridLayout_9->addWidget(eom_davidson_maxvectors, 1, 1, 1, 1);

        eom_davidson_max_iter = new QSpinBox(groupBox_14);
        eom_davidson_max_iter->setObjectName(QStringLiteral("eom_davidson_max_iter"));

        gridLayout_9->addWidget(eom_davidson_max_iter, 2, 1, 1, 1);

        eom_davidson_threshold = new QLineEdit(groupBox_14);
        eom_davidson_threshold->setObjectName(QStringLiteral("eom_davidson_threshold"));

        gridLayout_9->addWidget(eom_davidson_threshold, 3, 1, 1, 2);

        label_216 = new QLabel(groupBox_14);
        label_216->setObjectName(QStringLiteral("label_216"));

        gridLayout_9->addWidget(label_216, 3, 0, 1, 1);


        verticalLayout_2->addLayout(gridLayout_9);


        verticalLayout_4->addWidget(groupBox_14);

        verticalSpacer_8 = new QSpacerItem(20, 334, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_8);

        advancedOptionsStack->addWidget(AdvancedEOM);
        AdvancedADC = new QWidget();
        AdvancedADC->setObjectName(QStringLiteral("AdvancedADC"));
        verticalLayout_29 = new QVBoxLayout(AdvancedADC);
        verticalLayout_29->setObjectName(QStringLiteral("verticalLayout_29"));
        adc_guess = new QGroupBox(AdvancedADC);
        adc_guess->setObjectName(QStringLiteral("adc_guess"));
        gridLayout_19 = new QGridLayout(adc_guess);
        gridLayout_19->setObjectName(QStringLiteral("gridLayout_19"));
        label_197 = new QLabel(adc_guess);
        label_197->setObjectName(QStringLiteral("label_197"));

        gridLayout_19->addWidget(label_197, 0, 0, 1, 1);

        adc_nguess_singles = new QSpinBox(adc_guess);
        adc_nguess_singles->setObjectName(QStringLiteral("adc_nguess_singles"));

        gridLayout_19->addWidget(adc_nguess_singles, 0, 1, 1, 1);

        label_204 = new QLabel(adc_guess);
        label_204->setObjectName(QStringLiteral("label_204"));

        gridLayout_19->addWidget(label_204, 1, 0, 1, 1);

        adc_nguess_doubles = new QSpinBox(adc_guess);
        adc_nguess_doubles->setObjectName(QStringLiteral("adc_nguess_doubles"));

        gridLayout_19->addWidget(adc_nguess_doubles, 1, 1, 1, 1);


        verticalLayout_29->addWidget(adc_guess);

        adc_davidson = new QGroupBox(AdvancedADC);
        adc_davidson->setObjectName(QStringLiteral("adc_davidson"));
        verticalLayout_20 = new QVBoxLayout(adc_davidson);
        verticalLayout_20->setObjectName(QStringLiteral("verticalLayout_20"));
        gridLayout_adc_davidson = new QGridLayout();
        gridLayout_adc_davidson->setObjectName(QStringLiteral("gridLayout_adc_davidson"));
        label_217 = new QLabel(adc_davidson);
        label_217->setObjectName(QStringLiteral("label_217"));

        gridLayout_adc_davidson->addWidget(label_217, 0, 0, 1, 1);

        label_163 = new QLabel(adc_davidson);
        label_163->setObjectName(QStringLiteral("label_163"));

        gridLayout_adc_davidson->addWidget(label_163, 1, 0, 1, 1);

        label_168 = new QLabel(adc_davidson);
        label_168->setObjectName(QStringLiteral("label_168"));

        gridLayout_adc_davidson->addWidget(label_168, 2, 0, 1, 1);

        horizontalSpacer_37 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_adc_davidson->addItem(horizontalSpacer_37, 0, 2, 1, 1);

        adc_davidson_conv = new QSpinBox(adc_davidson);
        adc_davidson_conv->setObjectName(QStringLiteral("adc_davidson_conv"));

        gridLayout_adc_davidson->addWidget(adc_davidson_conv, 0, 1, 1, 1);

        adc_davidson_maxsubspace = new QSpinBox(adc_davidson);
        adc_davidson_maxsubspace->setObjectName(QStringLiteral("adc_davidson_maxsubspace"));

        gridLayout_adc_davidson->addWidget(adc_davidson_maxsubspace, 1, 1, 1, 1);

        adc_davidson_maxiter = new QSpinBox(adc_davidson);
        adc_davidson_maxiter->setObjectName(QStringLiteral("adc_davidson_maxiter"));

        gridLayout_adc_davidson->addWidget(adc_davidson_maxiter, 2, 1, 1, 1);

        label_218 = new QLabel(adc_davidson);
        label_218->setObjectName(QStringLiteral("label_218"));

        gridLayout_adc_davidson->addWidget(label_218, 3, 0, 1, 1);

        adc_davidson_thresh = new QSpinBox(adc_davidson);
        adc_davidson_thresh->setObjectName(QStringLiteral("adc_davidson_thresh"));

        gridLayout_adc_davidson->addWidget(adc_davidson_thresh, 3, 1, 1, 1);


        verticalLayout_20->addLayout(gridLayout_adc_davidson);


        verticalLayout_29->addWidget(adc_davidson);

        adc_diis = new QGroupBox(AdvancedADC);
        adc_diis->setObjectName(QStringLiteral("adc_diis"));
        verticalLayout_26 = new QVBoxLayout(adc_diis);
        verticalLayout_26->setObjectName(QStringLiteral("verticalLayout_26"));
        gridLayout_adc_diis = new QGridLayout();
        gridLayout_adc_diis->setObjectName(QStringLiteral("gridLayout_adc_diis"));
        label_42 = new QLabel(adc_diis);
        label_42->setObjectName(QStringLiteral("label_42"));

        gridLayout_adc_diis->addWidget(label_42, 1, 0, 1, 1);

        adc_diis_start = new QSpinBox(adc_diis);
        adc_diis_start->setObjectName(QStringLiteral("adc_diis_start"));

        gridLayout_adc_diis->addWidget(adc_diis_start, 2, 1, 1, 1);

        adc_diis_econv = new QSpinBox(adc_diis);
        adc_diis_econv->setObjectName(QStringLiteral("adc_diis_econv"));

        gridLayout_adc_diis->addWidget(adc_diis_econv, 0, 1, 1, 1);

        label_177 = new QLabel(adc_diis);
        label_177->setObjectName(QStringLiteral("label_177"));

        gridLayout_adc_diis->addWidget(label_177, 4, 0, 1, 1);

        adc_diis_rconv = new QSpinBox(adc_diis);
        adc_diis_rconv->setObjectName(QStringLiteral("adc_diis_rconv"));

        gridLayout_adc_diis->addWidget(adc_diis_rconv, 1, 1, 1, 1);

        label_219 = new QLabel(adc_diis);
        label_219->setObjectName(QStringLiteral("label_219"));

        gridLayout_adc_diis->addWidget(label_219, 0, 0, 1, 1);

        label_164 = new QLabel(adc_diis);
        label_164->setObjectName(QStringLiteral("label_164"));

        gridLayout_adc_diis->addWidget(label_164, 2, 0, 1, 1);

        adc_diis_maxiter = new QSpinBox(adc_diis);
        adc_diis_maxiter->setObjectName(QStringLiteral("adc_diis_maxiter"));

        gridLayout_adc_diis->addWidget(adc_diis_maxiter, 4, 1, 1, 1);

        horizontalSpacer_38 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_adc_diis->addItem(horizontalSpacer_38, 0, 2, 1, 1);

        label_52 = new QLabel(adc_diis);
        label_52->setObjectName(QStringLiteral("label_52"));

        gridLayout_adc_diis->addWidget(label_52, 3, 0, 1, 1);

        adc_diis_size = new QSpinBox(adc_diis);
        adc_diis_size->setObjectName(QStringLiteral("adc_diis_size"));

        gridLayout_adc_diis->addWidget(adc_diis_size, 3, 1, 1, 1);


        verticalLayout_26->addLayout(gridLayout_adc_diis);


        verticalLayout_29->addWidget(adc_diis);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_29->addItem(verticalSpacer_3);

        advancedOptionsStack->addWidget(AdvancedADC);
        AdvancedEOMStates = new QWidget();
        AdvancedEOMStates->setObjectName(QStringLiteral("AdvancedEOMStates"));
        verticalLayout_3 = new QVBoxLayout(AdvancedEOMStates);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_38 = new QLabel(AdvancedEOMStates);
        label_38->setObjectName(QStringLiteral("label_38"));

        verticalLayout_3->addWidget(label_38);

        gridLayout_10 = new QGridLayout();
        gridLayout_10->setObjectName(QStringLiteral("gridLayout_10"));
        ee_states = new QLineEdit(AdvancedEOMStates);
        ee_states->setObjectName(QStringLiteral("ee_states"));

        gridLayout_10->addWidget(ee_states, 0, 0, 1, 1);

        ee_singlets = new QLineEdit(AdvancedEOMStates);
        ee_singlets->setObjectName(QStringLiteral("ee_singlets"));

        gridLayout_10->addWidget(ee_singlets, 0, 1, 1, 1);

        ee_triplets = new QLineEdit(AdvancedEOMStates);
        ee_triplets->setObjectName(QStringLiteral("ee_triplets"));

        gridLayout_10->addWidget(ee_triplets, 1, 0, 1, 1);

        sf_states = new QLineEdit(AdvancedEOMStates);
        sf_states->setObjectName(QStringLiteral("sf_states"));

        gridLayout_10->addWidget(sf_states, 1, 1, 1, 1);

        dsf_states = new QLineEdit(AdvancedEOMStates);
        dsf_states->setObjectName(QStringLiteral("dsf_states"));

        gridLayout_10->addWidget(dsf_states, 2, 0, 1, 1);

        dip_states = new QLineEdit(AdvancedEOMStates);
        dip_states->setObjectName(QStringLiteral("dip_states"));

        gridLayout_10->addWidget(dip_states, 2, 1, 1, 1);

        dip_singlets = new QLineEdit(AdvancedEOMStates);
        dip_singlets->setObjectName(QStringLiteral("dip_singlets"));

        gridLayout_10->addWidget(dip_singlets, 3, 0, 1, 1);

        dip_triplets = new QLineEdit(AdvancedEOMStates);
        dip_triplets->setObjectName(QStringLiteral("dip_triplets"));

        gridLayout_10->addWidget(dip_triplets, 3, 1, 1, 1);

        ea_states = new QLineEdit(AdvancedEOMStates);
        ea_states->setObjectName(QStringLiteral("ea_states"));

        gridLayout_10->addWidget(ea_states, 4, 0, 1, 1);

        eom_ea_alpha = new QLineEdit(AdvancedEOMStates);
        eom_ea_alpha->setObjectName(QStringLiteral("eom_ea_alpha"));

        gridLayout_10->addWidget(eom_ea_alpha, 4, 1, 1, 1);

        eom_ea_beta = new QLineEdit(AdvancedEOMStates);
        eom_ea_beta->setObjectName(QStringLiteral("eom_ea_beta"));

        gridLayout_10->addWidget(eom_ea_beta, 5, 0, 1, 1);

        ip_states = new QLineEdit(AdvancedEOMStates);
        ip_states->setObjectName(QStringLiteral("ip_states"));

        gridLayout_10->addWidget(ip_states, 5, 1, 1, 1);

        eom_ip_alpha = new QLineEdit(AdvancedEOMStates);
        eom_ip_alpha->setObjectName(QStringLiteral("eom_ip_alpha"));

        gridLayout_10->addWidget(eom_ip_alpha, 6, 0, 1, 1);

        eom_ip_beta = new QLineEdit(AdvancedEOMStates);
        eom_ip_beta->setObjectName(QStringLiteral("eom_ip_beta"));

        gridLayout_10->addWidget(eom_ip_beta, 6, 1, 1, 1);


        verticalLayout_3->addLayout(gridLayout_10);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        cc_frzn_core = new QSpinBox(AdvancedEOMStates);
        cc_frzn_core->setObjectName(QStringLiteral("cc_frzn_core"));

        horizontalLayout_8->addWidget(cc_frzn_core);

        cc_rest_occ = new QSpinBox(AdvancedEOMStates);
        cc_rest_occ->setObjectName(QStringLiteral("cc_rest_occ"));

        horizontalLayout_8->addWidget(cc_rest_occ);

        cc_rest_vir = new QSpinBox(AdvancedEOMStates);
        cc_rest_vir->setObjectName(QStringLiteral("cc_rest_vir"));

        horizontalLayout_8->addWidget(cc_rest_vir);

        cc_frzn_virt = new QSpinBox(AdvancedEOMStates);
        cc_frzn_virt->setObjectName(QStringLiteral("cc_frzn_virt"));

        horizontalLayout_8->addWidget(cc_frzn_virt);


        verticalLayout_3->addLayout(horizontalLayout_8);

        verticalSpacer_2 = new QSpacerItem(20, 281, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);

        advancedOptionsStack->addWidget(AdvancedEOMStates);
        AdvancedSurfaceCrossing = new QWidget();
        AdvancedSurfaceCrossing->setObjectName(QStringLiteral("AdvancedSurfaceCrossing"));
        verticalLayout_8 = new QVBoxLayout(AdvancedSurfaceCrossing);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        gridLayout7 = new QGridLayout();
        gridLayout7->setObjectName(QStringLiteral("gridLayout7"));
        label_33 = new QLabel(AdvancedSurfaceCrossing);
        label_33->setObjectName(QStringLiteral("label_33"));

        gridLayout7->addWidget(label_33, 0, 0, 1, 1);

        xopt_state_1 = new QLineEdit(AdvancedSurfaceCrossing);
        xopt_state_1->setObjectName(QStringLiteral("xopt_state_1"));
        xopt_state_1->setMaximumSize(QSize(106, 16777215));

        gridLayout7->addWidget(xopt_state_1, 0, 1, 1, 1);

        label_73 = new QLabel(AdvancedSurfaceCrossing);
        label_73->setObjectName(QStringLiteral("label_73"));

        gridLayout7->addWidget(label_73, 1, 0, 1, 1);

        xopt_state_2 = new QLineEdit(AdvancedSurfaceCrossing);
        xopt_state_2->setObjectName(QStringLiteral("xopt_state_2"));
        xopt_state_2->setMaximumSize(QSize(106, 16777215));

        gridLayout7->addWidget(xopt_state_2, 1, 1, 1, 1);

        xopt_seam_only = new QCheckBox(AdvancedSurfaceCrossing);
        xopt_seam_only->setObjectName(QStringLiteral("xopt_seam_only"));

        gridLayout7->addWidget(xopt_seam_only, 2, 0, 1, 2);


        verticalLayout_8->addLayout(gridLayout7);

        spacerItem23 = new QSpacerItem(20, 435, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_8->addItem(spacerItem23);

        advancedOptionsStack->addWidget(AdvancedSurfaceCrossing);
        AdvancedWavefunctionAnalysis = new QWidget();
        AdvancedWavefunctionAnalysis->setObjectName(QStringLiteral("AdvancedWavefunctionAnalysis"));
        vboxLayout6 = new QVBoxLayout(AdvancedWavefunctionAnalysis);
        vboxLayout6->setObjectName(QStringLiteral("vboxLayout6"));
        wavefunction_analysis = new QCheckBox(AdvancedWavefunctionAnalysis);
        wavefunction_analysis->setObjectName(QStringLiteral("wavefunction_analysis"));

        vboxLayout6->addWidget(wavefunction_analysis);

        molden_format = new QCheckBox(AdvancedWavefunctionAnalysis);
        molden_format->setObjectName(QStringLiteral("molden_format"));

        vboxLayout6->addWidget(molden_format);

        mm_charges = new QCheckBox(AdvancedWavefunctionAnalysis);
        mm_charges->setObjectName(QStringLiteral("mm_charges"));

        vboxLayout6->addWidget(mm_charges);

        hirshfeld = new QCheckBox(AdvancedWavefunctionAnalysis);
        hirshfeld->setObjectName(QStringLiteral("hirshfeld"));

        vboxLayout6->addWidget(hirshfeld);

        hboxLayout6 = new QHBoxLayout();
        hboxLayout6->setObjectName(QStringLiteral("hboxLayout6"));
        label_176 = new QLabel(AdvancedWavefunctionAnalysis);
        label_176->setObjectName(QStringLiteral("label_176"));

        hboxLayout6->addWidget(label_176);

        spacerItem24 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout6->addItem(spacerItem24);

        multipole_order = new QSpinBox(AdvancedWavefunctionAnalysis);
        multipole_order->setObjectName(QStringLiteral("multipole_order"));

        hboxLayout6->addWidget(multipole_order);


        vboxLayout6->addLayout(hboxLayout6);

        label_114 = new QLabel(AdvancedWavefunctionAnalysis);
        label_114->setObjectName(QStringLiteral("label_114"));

        vboxLayout6->addWidget(label_114);

        hboxLayout7 = new QHBoxLayout();
        hboxLayout7->setObjectName(QStringLiteral("hboxLayout7"));
        mulliken = new QComboBox(AdvancedWavefunctionAnalysis);
        mulliken->setObjectName(QStringLiteral("mulliken"));

        hboxLayout7->addWidget(mulliken);

        horizontalSpacer_32 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout7->addItem(horizontalSpacer_32);


        vboxLayout6->addLayout(hboxLayout7);

        spacerItem25 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vboxLayout6->addItem(spacerItem25);

        advancedOptionsStack->addWidget(AdvancedWavefunctionAnalysis);
        AdvancedPlots = new QWidget();
        AdvancedPlots->setObjectName(QStringLiteral("AdvancedPlots"));
        vboxLayout7 = new QVBoxLayout(AdvancedPlots);
        vboxLayout7->setObjectName(QStringLiteral("vboxLayout7"));
        gridLayout8 = new QGridLayout();
        gridLayout8->setObjectName(QStringLiteral("gridLayout8"));
        gridLayout9 = new QGridLayout();
        gridLayout9->setObjectName(QStringLiteral("gridLayout9"));
        qui_plots_points = new QSpinBox(AdvancedPlots);
        qui_plots_points->setObjectName(QStringLiteral("qui_plots_points"));

        gridLayout9->addWidget(qui_plots_points, 0, 0, 1, 1);

        spacerItem26 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout9->addItem(spacerItem26, 0, 1, 1, 1);


        gridLayout8->addLayout(gridLayout9, 2, 1, 1, 1);

        label_149 = new QLabel(AdvancedPlots);
        label_149->setObjectName(QStringLiteral("label_149"));

        gridLayout8->addWidget(label_149, 2, 0, 1, 1);

        spacerItem27 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout8->addItem(spacerItem27, 1, 2, 1, 1);

        plots_grid = new QComboBox(AdvancedPlots);
        plots_grid->setObjectName(QStringLiteral("plots_grid"));

        gridLayout8->addWidget(plots_grid, 0, 1, 1, 1);

        plots_property = new QComboBox(AdvancedPlots);
        plots_property->setObjectName(QStringLiteral("plots_property"));

        gridLayout8->addWidget(plots_property, 1, 1, 1, 1);

        label_147 = new QLabel(AdvancedPlots);
        label_147->setObjectName(QStringLiteral("label_147"));

        gridLayout8->addWidget(label_147, 1, 0, 1, 1);

        label_148 = new QLabel(AdvancedPlots);
        label_148->setObjectName(QStringLiteral("label_148"));

        gridLayout8->addWidget(label_148, 0, 0, 1, 1);


        vboxLayout7->addLayout(gridLayout8);

        skip_cis_rpa = new QCheckBox(AdvancedPlots);
        skip_cis_rpa->setObjectName(QStringLiteral("skip_cis_rpa"));

        vboxLayout7->addWidget(skip_cis_rpa);

        spacerItem28 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vboxLayout7->addItem(spacerItem28);

        advancedOptionsStack->addWidget(AdvancedPlots);
        AdvancedMolecularProperties = new QWidget();
        AdvancedMolecularProperties->setObjectName(QStringLiteral("AdvancedMolecularProperties"));
        verticalLayout_35 = new QVBoxLayout(AdvancedMolecularProperties);
        verticalLayout_35->setObjectName(QStringLiteral("verticalLayout_35"));
        gridLayout10 = new QGridLayout();
        gridLayout10->setObjectName(QStringLiteral("gridLayout10"));
        label_172 = new QLabel(AdvancedMolecularProperties);
        label_172->setObjectName(QStringLiteral("label_172"));

        gridLayout10->addWidget(label_172, 4, 0, 1, 1);

        label_171 = new QLabel(AdvancedMolecularProperties);
        label_171->setObjectName(QStringLiteral("label_171"));

        gridLayout10->addWidget(label_171, 3, 0, 1, 1);

        moprop_max_cycles_level_1 = new QSpinBox(AdvancedMolecularProperties);
        moprop_max_cycles_level_1->setObjectName(QStringLiteral("moprop_max_cycles_level_1"));

        gridLayout10->addWidget(moprop_max_cycles_level_1, 3, 2, 1, 1);

        label_170 = new QLabel(AdvancedMolecularProperties);
        label_170->setObjectName(QStringLiteral("label_170"));

        gridLayout10->addWidget(label_170, 2, 0, 1, 1);

        label_173 = new QLabel(AdvancedMolecularProperties);
        label_173->setObjectName(QStringLiteral("label_173"));

        gridLayout10->addWidget(label_173, 2, 1, 1, 1);

        moprop_max_cycles_level_2 = new QSpinBox(AdvancedMolecularProperties);
        moprop_max_cycles_level_2->setObjectName(QStringLiteral("moprop_max_cycles_level_2"));

        gridLayout10->addWidget(moprop_max_cycles_level_2, 4, 2, 1, 1);

        moprop_convergence_level_1 = new QSpinBox(AdvancedMolecularProperties);
        moprop_convergence_level_1->setObjectName(QStringLiteral("moprop_convergence_level_1"));

        gridLayout10->addWidget(moprop_convergence_level_1, 3, 1, 1, 1);

        moprop_convergence_level_2 = new QSpinBox(AdvancedMolecularProperties);
        moprop_convergence_level_2->setObjectName(QStringLiteral("moprop_convergence_level_2"));

        gridLayout10->addWidget(moprop_convergence_level_2, 4, 1, 1, 1);

        label_174 = new QLabel(AdvancedMolecularProperties);
        label_174->setObjectName(QStringLiteral("label_174"));

        gridLayout10->addWidget(label_174, 2, 2, 1, 1);

        moprop_diis_subspace = new QSpinBox(AdvancedMolecularProperties);
        moprop_diis_subspace->setObjectName(QStringLiteral("moprop_diis_subspace"));

        gridLayout10->addWidget(moprop_diis_subspace, 1, 2, 1, 1);

        moprop_perturbations = new QSpinBox(AdvancedMolecularProperties);
        moprop_perturbations->setObjectName(QStringLiteral("moprop_perturbations"));

        gridLayout10->addWidget(moprop_perturbations, 0, 2, 1, 1);

        label_79 = new QLabel(AdvancedMolecularProperties);
        label_79->setObjectName(QStringLiteral("label_79"));

        gridLayout10->addWidget(label_79, 0, 0, 1, 2);

        label_175 = new QLabel(AdvancedMolecularProperties);
        label_175->setObjectName(QStringLiteral("label_175"));

        gridLayout10->addWidget(label_175, 1, 0, 1, 2);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout10->addItem(horizontalSpacer_4, 0, 3, 1, 1);


        verticalLayout_35->addLayout(gridLayout10);

        spacerItem29 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_35->addItem(spacerItem29);

        advancedOptionsStack->addWidget(AdvancedMolecularProperties);
        AdvancedGeometryOptimization = new QWidget();
        AdvancedGeometryOptimization->setObjectName(QStringLiteral("AdvancedGeometryOptimization"));
        verticalLayout_37 = new QVBoxLayout(AdvancedGeometryOptimization);
        verticalLayout_37->setObjectName(QStringLiteral("verticalLayout_37"));
        gridLayout11 = new QGridLayout();
        gridLayout11->setObjectName(QStringLiteral("gridLayout11"));
        label_44 = new QLabel(AdvancedGeometryOptimization);
        label_44->setObjectName(QStringLiteral("label_44"));

        gridLayout11->addWidget(label_44, 1, 0, 1, 1);

        geom_opt_hessian_update = new QComboBox(AdvancedGeometryOptimization);
        geom_opt_hessian_update->setObjectName(QStringLiteral("geom_opt_hessian_update"));

        gridLayout11->addWidget(geom_opt_hessian_update, 1, 1, 1, 1);

        label_72 = new QLabel(AdvancedGeometryOptimization);
        label_72->setObjectName(QStringLiteral("label_72"));

        gridLayout11->addWidget(label_72, 0, 0, 1, 1);

        geom_opt_coordinates = new QComboBox(AdvancedGeometryOptimization);
        geom_opt_coordinates->setObjectName(QStringLiteral("geom_opt_coordinates"));

        gridLayout11->addWidget(geom_opt_coordinates, 2, 1, 1, 1);

        geom_opt_hessian = new QComboBox(AdvancedGeometryOptimization);
        geom_opt_hessian->setObjectName(QStringLiteral("geom_opt_hessian"));

        gridLayout11->addWidget(geom_opt_hessian, 0, 1, 1, 1);

        label_14 = new QLabel(AdvancedGeometryOptimization);
        label_14->setObjectName(QStringLiteral("label_14"));

        gridLayout11->addWidget(label_14, 2, 0, 1, 1);

        spacerItem30 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout11->addItem(spacerItem30, 0, 2, 1, 1);

        hboxLayout8 = new QHBoxLayout();
        hboxLayout8->setObjectName(QStringLiteral("hboxLayout8"));
        spacerItem31 = new QSpacerItem(10, 10, QSizePolicy::Fixed, QSizePolicy::Minimum);

        hboxLayout8->addItem(spacerItem31);

        qui_geom_opt_fallback = new QCheckBox(AdvancedGeometryOptimization);
        qui_geom_opt_fallback->setObjectName(QStringLiteral("qui_geom_opt_fallback"));

        hboxLayout8->addWidget(qui_geom_opt_fallback);


        gridLayout11->addLayout(hboxLayout8, 3, 0, 1, 2);


        verticalLayout_37->addLayout(gridLayout11);

        gridLayout12 = new QGridLayout();
        gridLayout12->setObjectName(QStringLiteral("gridLayout12"));
        geom_opt_diis_subspace = new QSpinBox(AdvancedGeometryOptimization);
        geom_opt_diis_subspace->setObjectName(QStringLiteral("geom_opt_diis_subspace"));

        gridLayout12->addWidget(geom_opt_diis_subspace, 2, 1, 1, 1);

        label_70 = new QLabel(AdvancedGeometryOptimization);
        label_70->setObjectName(QStringLiteral("label_70"));

        gridLayout12->addWidget(label_70, 2, 0, 1, 1);

        label_45 = new QLabel(AdvancedGeometryOptimization);
        label_45->setObjectName(QStringLiteral("label_45"));

        gridLayout12->addWidget(label_45, 1, 0, 1, 1);

        geom_opt_print = new QSpinBox(AdvancedGeometryOptimization);
        geom_opt_print->setObjectName(QStringLiteral("geom_opt_print"));

        gridLayout12->addWidget(geom_opt_print, 1, 1, 1, 1);

        label_17 = new QLabel(AdvancedGeometryOptimization);
        label_17->setObjectName(QStringLiteral("label_17"));

        gridLayout12->addWidget(label_17, 0, 0, 1, 1);

        geom_opt_max_cycles = new QSpinBox(AdvancedGeometryOptimization);
        geom_opt_max_cycles->setObjectName(QStringLiteral("geom_opt_max_cycles"));

        gridLayout12->addWidget(geom_opt_max_cycles, 0, 1, 1, 1);

        horizontalSpacer_17 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout12->addItem(horizontalSpacer_17, 0, 2, 1, 1);


        verticalLayout_37->addLayout(gridLayout12);

        geom_opt_scf_guess_always = new QCheckBox(AdvancedGeometryOptimization);
        geom_opt_scf_guess_always->setObjectName(QStringLiteral("geom_opt_scf_guess_always"));

        verticalLayout_37->addWidget(geom_opt_scf_guess_always);

        geom_print = new QCheckBox(AdvancedGeometryOptimization);
        geom_print->setObjectName(QStringLiteral("geom_print"));

        verticalLayout_37->addWidget(geom_print);

        geom_opt_iproj = new QCheckBox(AdvancedGeometryOptimization);
        geom_opt_iproj->setObjectName(QStringLiteral("geom_opt_iproj"));

        verticalLayout_37->addWidget(geom_opt_iproj);

        geom_opt_symmetry = new QCheckBox(AdvancedGeometryOptimization);
        geom_opt_symmetry->setObjectName(QStringLiteral("geom_opt_symmetry"));

        verticalLayout_37->addWidget(geom_opt_symmetry);

        spacerItem32 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_37->addItem(spacerItem32);

        advancedOptionsStack->addWidget(AdvancedGeometryOptimization);
        AdvancedOptThresholds = new QWidget();
        AdvancedOptThresholds->setObjectName(QStringLiteral("AdvancedOptThresholds"));
        verticalLayout_36 = new QVBoxLayout(AdvancedOptThresholds);
        verticalLayout_36->setObjectName(QStringLiteral("verticalLayout_36"));
        gridLayout13 = new QGridLayout();
        gridLayout13->setObjectName(QStringLiteral("gridLayout13"));
        label_11 = new QLabel(AdvancedOptThresholds);
        label_11->setObjectName(QStringLiteral("label_11"));

        gridLayout13->addWidget(label_11, 2, 2, 1, 1);

        geom_opt_tol_energy = new QSpinBox(AdvancedOptThresholds);
        geom_opt_tol_energy->setObjectName(QStringLiteral("geom_opt_tol_energy"));

        gridLayout13->addWidget(geom_opt_tol_energy, 2, 1, 1, 1);

        label_10 = new QLabel(AdvancedOptThresholds);
        label_10->setObjectName(QStringLiteral("label_10"));

        gridLayout13->addWidget(label_10, 1, 0, 1, 1);

        label_113 = new QLabel(AdvancedOptThresholds);
        label_113->setObjectName(QStringLiteral("label_113"));

        gridLayout13->addWidget(label_113, 1, 2, 1, 1);

        geom_opt_tol_displacement = new QSpinBox(AdvancedOptThresholds);
        geom_opt_tol_displacement->setObjectName(QStringLiteral("geom_opt_tol_displacement"));

        gridLayout13->addWidget(geom_opt_tol_displacement, 1, 1, 1, 1);

        label_13 = new QLabel(AdvancedOptThresholds);
        label_13->setObjectName(QStringLiteral("label_13"));

        gridLayout13->addWidget(label_13, 0, 0, 1, 1);

        geom_opt_tol_gradient = new QSpinBox(AdvancedOptThresholds);
        geom_opt_tol_gradient->setObjectName(QStringLiteral("geom_opt_tol_gradient"));

        gridLayout13->addWidget(geom_opt_tol_gradient, 0, 1, 1, 1);

        label_15 = new QLabel(AdvancedOptThresholds);
        label_15->setObjectName(QStringLiteral("label_15"));

        gridLayout13->addWidget(label_15, 0, 2, 1, 1);

        label_12 = new QLabel(AdvancedOptThresholds);
        label_12->setObjectName(QStringLiteral("label_12"));

        gridLayout13->addWidget(label_12, 2, 0, 1, 1);

        label_68 = new QLabel(AdvancedOptThresholds);
        label_68->setObjectName(QStringLiteral("label_68"));

        gridLayout13->addWidget(label_68, 3, 0, 1, 1);

        geom_opt_linear_angle = new QSpinBox(AdvancedOptThresholds);
        geom_opt_linear_angle->setObjectName(QStringLiteral("geom_opt_linear_angle"));

        gridLayout13->addWidget(geom_opt_linear_angle, 3, 1, 1, 1);

        horizontalSpacer_15 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout13->addItem(horizontalSpacer_15, 0, 3, 1, 1);

        label_71 = new QLabel(AdvancedOptThresholds);
        label_71->setObjectName(QStringLiteral("label_71"));

        gridLayout13->addWidget(label_71, 4, 0, 1, 1);

        geom_opt_max_step_size = new QDoubleSpinBox(AdvancedOptThresholds);
        geom_opt_max_step_size->setObjectName(QStringLiteral("geom_opt_max_step_size"));
        geom_opt_max_step_size->setDecimals(3);
        geom_opt_max_step_size->setMaximum(9.99);

        gridLayout13->addWidget(geom_opt_max_step_size, 4, 1, 1, 1);


        verticalLayout_36->addLayout(gridLayout13);

        verticalSpacer_22 = new QSpacerItem(20, 375, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_36->addItem(verticalSpacer_22);

        advancedOptionsStack->addWidget(AdvancedOptThresholds);
        AdvancedReactionPathway = new QWidget();
        AdvancedReactionPathway->setObjectName(QStringLiteral("AdvancedReactionPathway"));
        verticalLayout_40 = new QVBoxLayout(AdvancedReactionPathway);
        verticalLayout_40->setObjectName(QStringLiteral("verticalLayout_40"));
        gridLayout_11 = new QGridLayout();
        gridLayout_11->setObjectName(QStringLiteral("gridLayout_11"));
        label_56 = new QLabel(AdvancedReactionPathway);
        label_56->setObjectName(QStringLiteral("label_56"));

        gridLayout_11->addWidget(label_56, 0, 0, 1, 1);

        label_58 = new QLabel(AdvancedReactionPathway);
        label_58->setObjectName(QStringLiteral("label_58"));

        gridLayout_11->addWidget(label_58, 1, 0, 1, 1);

        label_60 = new QLabel(AdvancedReactionPathway);
        label_60->setObjectName(QStringLiteral("label_60"));

        gridLayout_11->addWidget(label_60, 2, 0, 1, 1);

        rpath_max_stepsize = new QDoubleSpinBox(AdvancedReactionPathway);
        rpath_max_stepsize->setObjectName(QStringLiteral("rpath_max_stepsize"));
        rpath_max_stepsize->setDecimals(3);
        rpath_max_stepsize->setMaximum(0.999);
        rpath_max_stepsize->setSingleStep(0.001);

        gridLayout_11->addWidget(rpath_max_stepsize, 1, 1, 1, 1);

        rpath_tol_displacement = new QDoubleSpinBox(AdvancedReactionPathway);
        rpath_tol_displacement->setObjectName(QStringLiteral("rpath_tol_displacement"));
        rpath_tol_displacement->setDecimals(4);
        rpath_tol_displacement->setMaximum(0.9999);
        rpath_tol_displacement->setSingleStep(0.0001);

        gridLayout_11->addWidget(rpath_tol_displacement, 2, 1, 1, 1);

        label_59 = new QLabel(AdvancedReactionPathway);
        label_59->setObjectName(QStringLiteral("label_59"));

        gridLayout_11->addWidget(label_59, 3, 0, 1, 1);

        rpath_print = new QSpinBox(AdvancedReactionPathway);
        rpath_print->setObjectName(QStringLiteral("rpath_print"));

        gridLayout_11->addWidget(rpath_print, 3, 1, 1, 1);

        hboxLayout9 = new QHBoxLayout();
        hboxLayout9->setObjectName(QStringLiteral("hboxLayout9"));
        rpath_coordinates = new QComboBox(AdvancedReactionPathway);
        rpath_coordinates->setObjectName(QStringLiteral("rpath_coordinates"));

        hboxLayout9->addWidget(rpath_coordinates);

        spacerItem33 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout9->addItem(spacerItem33);


        gridLayout_11->addLayout(hboxLayout9, 0, 1, 1, 2);

        spacerItem34 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_11->addItem(spacerItem34, 1, 2, 1, 1);


        verticalLayout_40->addLayout(gridLayout_11);

        verticalSpacer_21 = new QSpacerItem(20, 374, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_40->addItem(verticalSpacer_21);

        advancedOptionsStack->addWidget(AdvancedReactionPathway);
        AdvancedMolecularDynamics = new QWidget();
        AdvancedMolecularDynamics->setObjectName(QStringLiteral("AdvancedMolecularDynamics"));
        vboxLayout8 = new QVBoxLayout(AdvancedMolecularDynamics);
        vboxLayout8->setObjectName(QStringLiteral("vboxLayout8"));
        gridLayout14 = new QGridLayout();
        gridLayout14->setObjectName(QStringLiteral("gridLayout14"));
        aimd_moments = new QSpinBox(AdvancedMolecularDynamics);
        aimd_moments->setObjectName(QStringLiteral("aimd_moments"));

        gridLayout14->addWidget(aimd_moments, 0, 1, 1, 1);

        label_103 = new QLabel(AdvancedMolecularDynamics);
        label_103->setObjectName(QStringLiteral("label_103"));

        gridLayout14->addWidget(label_103, 0, 0, 1, 1);

        aimd_fock_extrapolation_order = new QSpinBox(AdvancedMolecularDynamics);
        aimd_fock_extrapolation_order->setObjectName(QStringLiteral("aimd_fock_extrapolation_order"));

        gridLayout14->addWidget(aimd_fock_extrapolation_order, 1, 1, 1, 1);

        label_140 = new QLabel(AdvancedMolecularDynamics);
        label_140->setObjectName(QStringLiteral("label_140"));

        gridLayout14->addWidget(label_140, 2, 0, 1, 1);

        label_116 = new QLabel(AdvancedMolecularDynamics);
        label_116->setObjectName(QStringLiteral("label_116"));

        gridLayout14->addWidget(label_116, 1, 0, 1, 1);

        aimd_fock_extrapolation_points = new QSpinBox(AdvancedMolecularDynamics);
        aimd_fock_extrapolation_points->setObjectName(QStringLiteral("aimd_fock_extrapolation_points"));

        gridLayout14->addWidget(aimd_fock_extrapolation_points, 2, 1, 1, 1);

        spacerItem35 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout14->addItem(spacerItem35, 0, 2, 1, 1);


        vboxLayout8->addLayout(gridLayout14);

        spacerItem36 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vboxLayout8->addItem(spacerItem36);

        advancedOptionsStack->addWidget(AdvancedMolecularDynamics);
        AdvancedEFPOptions = new QWidget();
        AdvancedEFPOptions->setObjectName(QStringLiteral("AdvancedEFPOptions"));
        verticalLayout_5 = new QVBoxLayout(AdvancedEFPOptions);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        efp = new QCheckBox(AdvancedEFPOptions);
        efp->setObjectName(QStringLiteral("efp"));

        verticalLayout_5->addWidget(efp);

        efp_fragments_only = new QCheckBox(AdvancedEFPOptions);
        efp_fragments_only->setObjectName(QStringLiteral("efp_fragments_only"));

        verticalLayout_5->addWidget(efp_fragments_only);

        efp_input = new QCheckBox(AdvancedEFPOptions);
        efp_input->setObjectName(QStringLiteral("efp_input"));

        verticalLayout_5->addWidget(efp_input);

        verticalSpacer = new QSpacerItem(20, 460, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer);

        advancedOptionsStack->addWidget(AdvancedEFPOptions);
        AdvancedNMRChemicalShifts = new QWidget();
        AdvancedNMRChemicalShifts->setObjectName(QStringLiteral("AdvancedNMRChemicalShifts"));
        verticalLayout_41 = new QVBoxLayout(AdvancedNMRChemicalShifts);
        verticalLayout_41->setObjectName(QStringLiteral("verticalLayout_41"));
        gridLayout15 = new QGridLayout();
        gridLayout15->setObjectName(QStringLiteral("gridLayout15"));
        spacerItem37 = new QSpacerItem(91, 22, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout15->addItem(spacerItem37, 1, 3, 1, 1);

        label_110 = new QLabel(AdvancedNMRChemicalShifts);
        label_110->setObjectName(QStringLiteral("label_110"));

        gridLayout15->addWidget(label_110, 1, 2, 1, 1);

        dscf_convergence_level_2 = new QSpinBox(AdvancedNMRChemicalShifts);
        dscf_convergence_level_2->setObjectName(QStringLiteral("dscf_convergence_level_2"));

        gridLayout15->addWidget(dscf_convergence_level_2, 3, 1, 1, 1);

        dscf_max_cycles_level_2 = new QSpinBox(AdvancedNMRChemicalShifts);
        dscf_max_cycles_level_2->setObjectName(QStringLiteral("dscf_max_cycles_level_2"));

        gridLayout15->addWidget(dscf_max_cycles_level_2, 3, 2, 1, 1);

        dscf_max_cycles_level_1 = new QSpinBox(AdvancedNMRChemicalShifts);
        dscf_max_cycles_level_1->setObjectName(QStringLiteral("dscf_max_cycles_level_1"));

        gridLayout15->addWidget(dscf_max_cycles_level_1, 2, 2, 1, 1);

        label_109 = new QLabel(AdvancedNMRChemicalShifts);
        label_109->setObjectName(QStringLiteral("label_109"));

        gridLayout15->addWidget(label_109, 1, 1, 1, 1);

        dscf_convergence_level_1 = new QSpinBox(AdvancedNMRChemicalShifts);
        dscf_convergence_level_1->setObjectName(QStringLiteral("dscf_convergence_level_1"));

        gridLayout15->addWidget(dscf_convergence_level_1, 2, 1, 1, 1);

        label_111 = new QLabel(AdvancedNMRChemicalShifts);
        label_111->setObjectName(QStringLiteral("label_111"));

        gridLayout15->addWidget(label_111, 1, 0, 1, 1);

        label_112 = new QLabel(AdvancedNMRChemicalShifts);
        label_112->setObjectName(QStringLiteral("label_112"));

        gridLayout15->addWidget(label_112, 0, 0, 1, 2);

        dscf_diis_subspace = new QSpinBox(AdvancedNMRChemicalShifts);
        dscf_diis_subspace->setObjectName(QStringLiteral("dscf_diis_subspace"));

        gridLayout15->addWidget(dscf_diis_subspace, 0, 2, 1, 1);

        label_107 = new QLabel(AdvancedNMRChemicalShifts);
        label_107->setObjectName(QStringLiteral("label_107"));

        gridLayout15->addWidget(label_107, 2, 0, 1, 1);

        label_108 = new QLabel(AdvancedNMRChemicalShifts);
        label_108->setObjectName(QStringLiteral("label_108"));

        gridLayout15->addWidget(label_108, 3, 0, 1, 1);


        verticalLayout_41->addLayout(gridLayout15);

        dcpscf_perturbations = new QCheckBox(AdvancedNMRChemicalShifts);
        dcpscf_perturbations->setObjectName(QStringLiteral("dcpscf_perturbations"));

        verticalLayout_41->addWidget(dcpscf_perturbations);

        spacerItem38 = new QSpacerItem(193, 379, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_41->addItem(spacerItem38);

        advancedOptionsStack->addWidget(AdvancedNMRChemicalShifts);
        AdvancedFrequencies = new QWidget();
        AdvancedFrequencies->setObjectName(QStringLiteral("AdvancedFrequencies"));
        verticalLayout_42 = new QVBoxLayout(AdvancedFrequencies);
        verticalLayout_42->setObjectName(QStringLiteral("verticalLayout_42"));
        gridLayout16 = new QGridLayout();
        gridLayout16->setObjectName(QStringLiteral("gridLayout16"));
        label_150 = new QLabel(AdvancedFrequencies);
        label_150->setObjectName(QStringLiteral("label_150"));

        gridLayout16->addWidget(label_150, 2, 0, 1, 1);

        label_88 = new QLabel(AdvancedFrequencies);
        label_88->setObjectName(QStringLiteral("label_88"));

        gridLayout16->addWidget(label_88, 3, 0, 1, 1);

        label_74 = new QLabel(AdvancedFrequencies);
        label_74->setObjectName(QStringLiteral("label_74"));

        gridLayout16->addWidget(label_74, 1, 0, 1, 1);

        label_vp = new QLabel(AdvancedFrequencies);
        label_vp->setObjectName(QStringLiteral("label_vp"));

        gridLayout16->addWidget(label_vp, 0, 0, 1, 1);

        hboxLayout10 = new QHBoxLayout();
        hboxLayout10->setObjectName(QStringLiteral("hboxLayout10"));
        cpscf_nseg = new QSpinBox(AdvancedFrequencies);
        cpscf_nseg->setObjectName(QStringLiteral("cpscf_nseg"));
        QSizePolicy sizePolicy8(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy8.setHorizontalStretch(0);
        sizePolicy8.setVerticalStretch(0);
        sizePolicy8.setHeightForWidth(cpscf_nseg->sizePolicy().hasHeightForWidth());
        cpscf_nseg->setSizePolicy(sizePolicy8);

        hboxLayout10->addWidget(cpscf_nseg);

        spacerItem39 = new QSpacerItem(16, 27, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout10->addItem(spacerItem39);


        gridLayout16->addLayout(hboxLayout10, 1, 1, 1, 1);

        hboxLayout11 = new QHBoxLayout();
        hboxLayout11->setObjectName(QStringLiteral("hboxLayout11"));
        vibman_print = new QSpinBox(AdvancedFrequencies);
        vibman_print->setObjectName(QStringLiteral("vibman_print"));

        hboxLayout11->addWidget(vibman_print);

        spacerItem40 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout11->addItem(spacerItem40);


        gridLayout16->addLayout(hboxLayout11, 0, 1, 1, 1);

        hboxLayout12 = new QHBoxLayout();
        hboxLayout12->setObjectName(QStringLiteral("hboxLayout12"));
        analytic_derivative_order = new QSpinBox(AdvancedFrequencies);
        analytic_derivative_order->setObjectName(QStringLiteral("analytic_derivative_order"));

        hboxLayout12->addWidget(analytic_derivative_order);

        spacerItem41 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout12->addItem(spacerItem41);


        gridLayout16->addLayout(hboxLayout12, 2, 1, 1, 1);

        fd_step_size = new QDoubleSpinBox(AdvancedFrequencies);
        fd_step_size->setObjectName(QStringLiteral("fd_step_size"));
        fd_step_size->setDecimals(5);

        gridLayout16->addWidget(fd_step_size, 3, 1, 1, 1);


        verticalLayout_42->addLayout(gridLayout16);

        label_95 = new QLabel(AdvancedFrequencies);
        label_95->setObjectName(QStringLiteral("label_95"));

        verticalLayout_42->addWidget(label_95);

        horizontalLayout_21 = new QHBoxLayout();
        horizontalLayout_21->setObjectName(QStringLiteral("horizontalLayout_21"));
        horizontalSpacer_36 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_21->addItem(horizontalSpacer_36);

        fd_derivative_type = new QComboBox(AdvancedFrequencies);
        fd_derivative_type->setObjectName(QStringLiteral("fd_derivative_type"));

        horizontalLayout_21->addWidget(fd_derivative_type);


        verticalLayout_42->addLayout(horizontalLayout_21);

        spacerItem42 = new QSpacerItem(20, 191, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_42->addItem(spacerItem42);

        advancedOptionsStack->addWidget(AdvancedFrequencies);
        AdvancedQMMM = new QWidget();
        AdvancedQMMM->setObjectName(QStringLiteral("AdvancedQMMM"));
        vboxLayout9 = new QVBoxLayout(AdvancedQMMM);
        vboxLayout9->setObjectName(QStringLiteral("vboxLayout9"));
        hboxLayout13 = new QHBoxLayout();
        hboxLayout13->setObjectName(QStringLiteral("hboxLayout13"));
        readChargesButton = new QPushButton(AdvancedQMMM);
        readChargesButton->setObjectName(QStringLiteral("readChargesButton"));

        hboxLayout13->addWidget(readChargesButton);

        spacerItem43 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout13->addItem(spacerItem43);


        vboxLayout9->addLayout(hboxLayout13);

        gaussian_blur = new QCheckBox(AdvancedQMMM);
        gaussian_blur->setObjectName(QStringLiteral("gaussian_blur"));

        vboxLayout9->addWidget(gaussian_blur);

        qmmm = new QCheckBox(AdvancedQMMM);
        qmmm->setObjectName(QStringLiteral("qmmm"));

        vboxLayout9->addWidget(qmmm);

        qmmm_charges = new QCheckBox(AdvancedQMMM);
        qmmm_charges->setObjectName(QStringLiteral("qmmm_charges"));

        vboxLayout9->addWidget(qmmm_charges);

        link_atom_projection = new QCheckBox(AdvancedQMMM);
        link_atom_projection->setObjectName(QStringLiteral("link_atom_projection"));

        vboxLayout9->addWidget(link_atom_projection);

        qmmm_full_hessian = new QCheckBox(AdvancedQMMM);
        qmmm_full_hessian->setObjectName(QStringLiteral("qmmm_full_hessian"));

        vboxLayout9->addWidget(qmmm_full_hessian);

        spacerItem44 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vboxLayout9->addItem(spacerItem44);

        advancedOptionsStack->addWidget(AdvancedQMMM);
        AdvancedSolventModel = new QWidget();
        AdvancedSolventModel->setObjectName(QStringLiteral("AdvancedSolventModel"));
        verticalLayout_51 = new QVBoxLayout(AdvancedSolventModel);
        verticalLayout_51->setObjectName(QStringLiteral("verticalLayout_51"));
        gridLayout_5 = new QGridLayout();
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        label_64 = new QLabel(AdvancedSolventModel);
        label_64->setObjectName(QStringLiteral("label_64"));

        gridLayout_5->addWidget(label_64, 0, 0, 1, 1);

        solvent_method = new QComboBox(AdvancedSolventModel);
        solvent_method->setObjectName(QStringLiteral("solvent_method"));

        gridLayout_5->addWidget(solvent_method, 0, 1, 1, 1);


        verticalLayout_51->addLayout(gridLayout_5);

        solventGroupBox = new QGroupBox(AdvancedSolventModel);
        solventGroupBox->setObjectName(QStringLiteral("solventGroupBox"));
        gridLayout_23 = new QGridLayout(solventGroupBox);
        gridLayout_23->setObjectName(QStringLiteral("gridLayout_23"));
        label_b160_3 = new QLabel(solventGroupBox);
        label_b160_3->setObjectName(QStringLiteral("label_b160_3"));

        gridLayout_23->addWidget(label_b160_3, 0, 0, 1, 1);

        label_a160 = new QLabel(solventGroupBox);
        label_a160->setObjectName(QStringLiteral("label_a160"));

        gridLayout_23->addWidget(label_a160, 2, 0, 1, 1);

        qui_solvent_cavityradius = new QDoubleSpinBox(solventGroupBox);
        qui_solvent_cavityradius->setObjectName(QStringLiteral("qui_solvent_cavityradius"));
        qui_solvent_cavityradius->setDecimals(4);
        qui_solvent_cavityradius->setMaximum(99.9999);
        qui_solvent_cavityradius->setSingleStep(0.0001);

        gridLayout_23->addWidget(qui_solvent_cavityradius, 2, 1, 1, 1);

        qui_solvent_opticaldielectric = new QDoubleSpinBox(solventGroupBox);
        qui_solvent_opticaldielectric->setObjectName(QStringLiteral("qui_solvent_opticaldielectric"));
        qui_solvent_opticaldielectric->setDecimals(4);

        gridLayout_23->addWidget(qui_solvent_opticaldielectric, 1, 1, 1, 1);

        qui_solvent_dielectric = new QDoubleSpinBox(solventGroupBox);
        qui_solvent_dielectric->setObjectName(QStringLiteral("qui_solvent_dielectric"));
        qui_solvent_dielectric->setDecimals(4);
        qui_solvent_dielectric->setMaximum(99.9999);
        qui_solvent_dielectric->setSingleStep(0.0001);

        gridLayout_23->addWidget(qui_solvent_dielectric, 0, 1, 1, 1);

        label_97 = new QLabel(solventGroupBox);
        label_97->setObjectName(QStringLiteral("label_97"));

        gridLayout_23->addWidget(label_97, 1, 0, 1, 1);


        verticalLayout_51->addWidget(solventGroupBox);

        groupBox_4 = new QGroupBox(AdvancedSolventModel);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        verticalLayout_23 = new QVBoxLayout(groupBox_4);
        verticalLayout_23->setObjectName(QStringLiteral("verticalLayout_23"));
        solventStack = new QStackedWidget(groupBox_4);
        solventStack->setObjectName(QStringLiteral("solventStack"));
        sizePolicy1.setHeightForWidth(solventStack->sizePolicy().hasHeightForWidth());
        solventStack->setSizePolicy(sizePolicy1);
        SolventNone = new QWidget();
        SolventNone->setObjectName(QStringLiteral("SolventNone"));
        solventStack->addWidget(SolventNone);
        SolventOnsager = new QWidget();
        SolventOnsager->setObjectName(QStringLiteral("SolventOnsager"));
        verticalLayout_27 = new QVBoxLayout(SolventOnsager);
        verticalLayout_27->setObjectName(QStringLiteral("verticalLayout_27"));
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        label_37 = new QLabel(SolventOnsager);
        label_37->setObjectName(QStringLiteral("label_37"));

        horizontalLayout_10->addWidget(label_37);

        qui_solvent_multipoleorder = new QSpinBox(SolventOnsager);
        qui_solvent_multipoleorder->setObjectName(QStringLiteral("qui_solvent_multipoleorder"));

        horizontalLayout_10->addWidget(qui_solvent_multipoleorder);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_2);


        verticalLayout_27->addLayout(horizontalLayout_10);

        spacerItem45 = new QSpacerItem(20, 231, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_27->addItem(spacerItem45);

        solventStack->addWidget(SolventOnsager);
        SolventPCM = new QWidget();
        SolventPCM->setObjectName(QStringLiteral("SolventPCM"));
        verticalLayout_22 = new QVBoxLayout(SolventPCM);
        verticalLayout_22->setObjectName(QStringLiteral("verticalLayout_22"));
        gridLayout_20 = new QGridLayout();
        gridLayout_20->setObjectName(QStringLiteral("gridLayout_20"));
        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        qui_pcm_printlevel = new QSpinBox(SolventPCM);
        qui_pcm_printlevel->setObjectName(QStringLiteral("qui_pcm_printlevel"));

        horizontalLayout_13->addWidget(qui_pcm_printlevel);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_12);


        gridLayout_20->addLayout(horizontalLayout_13, 3, 1, 1, 1);

        label_75 = new QLabel(SolventPCM);
        label_75->setObjectName(QStringLiteral("label_75"));

        gridLayout_20->addWidget(label_75, 3, 0, 1, 1);

        qui_pcm_theory = new QComboBox(SolventPCM);
        qui_pcm_theory->setObjectName(QStringLiteral("qui_pcm_theory"));

        gridLayout_20->addWidget(qui_pcm_theory, 0, 1, 1, 1);

        label_80 = new QLabel(SolventPCM);
        label_80->setObjectName(QStringLiteral("label_80"));

        gridLayout_20->addWidget(label_80, 0, 0, 1, 1);

        label_81 = new QLabel(SolventPCM);
        label_81->setObjectName(QStringLiteral("label_81"));

        gridLayout_20->addWidget(label_81, 1, 0, 1, 1);

        qui_pcm_method = new QComboBox(SolventPCM);
        qui_pcm_method->setObjectName(QStringLiteral("qui_pcm_method"));

        gridLayout_20->addWidget(qui_pcm_method, 1, 1, 1, 1);

        label_96 = new QLabel(SolventPCM);
        label_96->setObjectName(QStringLiteral("label_96"));

        gridLayout_20->addWidget(label_96, 2, 0, 1, 1);

        qui_pcm_radii = new QComboBox(SolventPCM);
        qui_pcm_radii->setObjectName(QStringLiteral("qui_pcm_radii"));

        gridLayout_20->addWidget(qui_pcm_radii, 2, 1, 1, 1);


        verticalLayout_22->addLayout(gridLayout_20);

        verticalSpacer_9 = new QSpacerItem(20, 354, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_22->addItem(verticalSpacer_9);

        solventStack->addWidget(SolventPCM);
        SolventSVP = new QWidget();
        SolventSVP->setObjectName(QStringLiteral("SolventSVP"));
        vboxLayout10 = new QVBoxLayout(SolventSVP);
        vboxLayout10->setObjectName(QStringLiteral("vboxLayout10"));
        gridLayout_6 = new QGridLayout();
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        label_f161 = new QLabel(SolventSVP);
        label_f161->setObjectName(QStringLiteral("label_f161"));

        gridLayout_6->addWidget(label_f161, 0, 0, 1, 1);

        qui_svp_memory = new QSpinBox(SolventSVP);
        qui_svp_memory->setObjectName(QStringLiteral("qui_svp_memory"));

        gridLayout_6->addWidget(qui_svp_memory, 0, 1, 1, 1);

        label_d161 = new QLabel(SolventSVP);
        label_d161->setObjectName(QStringLiteral("label_d161"));
        QSizePolicy sizePolicy9(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy9.setHorizontalStretch(0);
        sizePolicy9.setVerticalStretch(0);
        sizePolicy9.setHeightForWidth(label_d161->sizePolicy().hasHeightForWidth());
        label_d161->setSizePolicy(sizePolicy9);

        gridLayout_6->addWidget(label_d161, 1, 0, 1, 1);

        qui_svp_cavity_conv = new QSpinBox(SolventSVP);
        qui_svp_cavity_conv->setObjectName(QStringLiteral("qui_svp_cavity_conv"));

        gridLayout_6->addWidget(qui_svp_cavity_conv, 1, 1, 1, 1);

        label_e161 = new QLabel(SolventSVP);
        label_e161->setObjectName(QStringLiteral("label_e161"));
        sizePolicy9.setHeightForWidth(label_e161->sizePolicy().hasHeightForWidth());
        label_e161->setSizePolicy(sizePolicy9);

        gridLayout_6->addWidget(label_e161, 2, 0, 1, 1);

        qui_svp_charge_conv = new QSpinBox(SolventSVP);
        qui_svp_charge_conv->setObjectName(QStringLiteral("qui_svp_charge_conv"));

        gridLayout_6->addWidget(qui_svp_charge_conv, 2, 1, 1, 1);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        label_c161 = new QLabel(SolventSVP);
        label_c161->setObjectName(QStringLiteral("label_c161"));

        horizontalLayout_12->addWidget(label_c161);

        spacer_2 = new QSpacerItem(85, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(spacer_2);

        qui_svp_guess = new QComboBox(SolventSVP);
        qui_svp_guess->setObjectName(QStringLiteral("qui_svp_guess"));

        horizontalLayout_12->addWidget(qui_svp_guess);


        gridLayout_6->addLayout(horizontalLayout_12, 3, 0, 1, 2);

        qui_svp_path = new QCheckBox(SolventSVP);
        qui_svp_path->setObjectName(QStringLiteral("qui_svp_path"));

        gridLayout_6->addWidget(qui_svp_path, 4, 0, 1, 1);


        vboxLayout10->addLayout(gridLayout_6);

        spacerItem46 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vboxLayout10->addItem(spacerItem46);

        solventStack->addWidget(SolventSVP);
        SolventCosmo = new QWidget();
        SolventCosmo->setObjectName(QStringLiteral("SolventCosmo"));
        verticalLayout_28 = new QVBoxLayout(SolventCosmo);
        verticalLayout_28->setObjectName(QStringLiteral("verticalLayout_28"));
        solventStack->addWidget(SolventCosmo);
        SolventChemSol = new QWidget();
        SolventChemSol->setObjectName(QStringLiteral("SolventChemSol"));
        verticalLayout_53 = new QVBoxLayout(SolventChemSol);
        verticalLayout_53->setObjectName(QStringLiteral("verticalLayout_53"));
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        label_162b = new QLabel(SolventChemSol);
        label_162b->setObjectName(QStringLiteral("label_162b"));

        horizontalLayout_11->addWidget(label_162b);

        qui_chemsol_efield = new QComboBox(SolventChemSol);
        qui_chemsol_efield->setObjectName(QStringLiteral("qui_chemsol_efield"));

        horizontalLayout_11->addWidget(qui_chemsol_efield);


        verticalLayout_53->addLayout(horizontalLayout_11);

        hboxLayout14 = new QHBoxLayout();
        hboxLayout14->setObjectName(QStringLiteral("hboxLayout14"));
        label_162a = new QLabel(SolventChemSol);
        label_162a->setObjectName(QStringLiteral("label_162a"));

        hboxLayout14->addWidget(label_162a);

        spacerItem47 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout14->addItem(spacerItem47);

        qui_chemsol_ngrids = new QSpinBox(SolventChemSol);
        qui_chemsol_ngrids->setObjectName(QStringLiteral("qui_chemsol_ngrids"));

        hboxLayout14->addWidget(qui_chemsol_ngrids);


        verticalLayout_53->addLayout(hboxLayout14);

        hboxLayout15 = new QHBoxLayout();
        hboxLayout15->setObjectName(QStringLiteral("hboxLayout15"));
        qui_chemsol_print = new QCheckBox(SolventChemSol);
        qui_chemsol_print->setObjectName(QStringLiteral("qui_chemsol_print"));

        hboxLayout15->addWidget(qui_chemsol_print);

        spacerItem48 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout15->addItem(spacerItem48);


        verticalLayout_53->addLayout(hboxLayout15);

        spacerItem49 = new QSpacerItem(20, 163, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_53->addItem(spacerItem49);

        solventStack->addWidget(SolventChemSol);
        SolventSMx = new QWidget();
        SolventSMx->setObjectName(QStringLiteral("SolventSMx"));
        verticalLayout_52 = new QVBoxLayout(SolventSMx);
        verticalLayout_52->setObjectName(QStringLiteral("verticalLayout_52"));
        gridLayout_18 = new QGridLayout();
        gridLayout_18->setObjectName(QStringLiteral("gridLayout_18"));
        label_65 = new QLabel(SolventSMx);
        label_65->setObjectName(QStringLiteral("label_65"));

        gridLayout_18->addWidget(label_65, 0, 0, 1, 1);

        qui_smx_solvent = new QComboBox(SolventSMx);
        qui_smx_solvent->setObjectName(QStringLiteral("qui_smx_solvent"));

        gridLayout_18->addWidget(qui_smx_solvent, 0, 1, 1, 1);

        label_54 = new QLabel(SolventSMx);
        label_54->setObjectName(QStringLiteral("label_54"));

        gridLayout_18->addWidget(label_54, 1, 0, 1, 1);

        qui_smx_charges = new QComboBox(SolventSMx);
        qui_smx_charges->setObjectName(QStringLiteral("qui_smx_charges"));

        gridLayout_18->addWidget(qui_smx_charges, 1, 1, 1, 1);


        verticalLayout_52->addLayout(gridLayout_18);

        spacerItem50 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_52->addItem(spacerItem50);

        solventStack->addWidget(SolventSMx);

        verticalLayout_23->addWidget(solventStack);


        verticalLayout_51->addWidget(groupBox_4);

        advancedOptionsStack->addWidget(AdvancedSolventModel);
        AdvancedSVPGrid = new QWidget();
        AdvancedSVPGrid->setObjectName(QStringLiteral("AdvancedSVPGrid"));
        vboxLayout11 = new QVBoxLayout(AdvancedSVPGrid);
        vboxLayout11->setObjectName(QStringLiteral("vboxLayout11"));
        groupBox = new QGroupBox(AdvancedSVPGrid);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        sizePolicy1.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy1);
        vboxLayout12 = new QVBoxLayout(groupBox);
        vboxLayout12->setObjectName(QStringLiteral("vboxLayout12"));
        hboxLayout16 = new QHBoxLayout();
        hboxLayout16->setObjectName(QStringLiteral("hboxLayout16"));
        label_128 = new QLabel(groupBox);
        label_128->setObjectName(QStringLiteral("label_128"));

        hboxLayout16->addWidget(label_128);

        qui_svp_nptleb = new QComboBox(groupBox);
        qui_svp_nptleb->setObjectName(QStringLiteral("qui_svp_nptleb"));

        hboxLayout16->addWidget(qui_svp_nptleb);


        vboxLayout12->addLayout(hboxLayout16);

        qui_svp_intcav = new QCheckBox(groupBox);
        qui_svp_intcav->setObjectName(QStringLiteral("qui_svp_intcav"));

        vboxLayout12->addWidget(qui_svp_intcav);

        hboxLayout17 = new QHBoxLayout();
        hboxLayout17->setObjectName(QStringLiteral("hboxLayout17"));
        label_129 = new QLabel(groupBox);
        label_129->setObjectName(QStringLiteral("label_129"));

        hboxLayout17->addWidget(label_129);

        qui_svp_nptthe = new QSpinBox(groupBox);
        qui_svp_nptthe->setObjectName(QStringLiteral("qui_svp_nptthe"));

        hboxLayout17->addWidget(qui_svp_nptthe);

        label_130 = new QLabel(groupBox);
        label_130->setObjectName(QStringLiteral("label_130"));

        hboxLayout17->addWidget(label_130);

        qui_svp_nptphi = new QSpinBox(groupBox);
        qui_svp_nptphi->setObjectName(QStringLiteral("qui_svp_nptphi"));

        hboxLayout17->addWidget(qui_svp_nptphi);


        vboxLayout12->addLayout(hboxLayout17);


        vboxLayout11->addWidget(groupBox);

        groupBox_6 = new QGroupBox(AdvancedSVPGrid);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));
        vboxLayout13 = new QVBoxLayout(groupBox_6);
        vboxLayout13->setObjectName(QStringLiteral("vboxLayout13"));
        label_131 = new QLabel(groupBox_6);
        label_131->setObjectName(QStringLiteral("label_131"));

        vboxLayout13->addWidget(label_131);

        qui_svp_itrngr = new QComboBox(groupBox_6);
        qui_svp_itrngr->setObjectName(QStringLiteral("qui_svp_itrngr"));

        vboxLayout13->addWidget(qui_svp_itrngr);

        gridLayout17 = new QGridLayout();
        gridLayout17->setObjectName(QStringLiteral("gridLayout17"));
        label_134 = new QLabel(groupBox_6);
        label_134->setObjectName(QStringLiteral("label_134"));

        gridLayout17->addWidget(label_134, 0, 0, 1, 1);

        label_135 = new QLabel(groupBox_6);
        label_135->setObjectName(QStringLiteral("label_135"));

        gridLayout17->addWidget(label_135, 0, 1, 1, 1);

        qui_svp_tranx = new QDoubleSpinBox(groupBox_6);
        qui_svp_tranx->setObjectName(QStringLiteral("qui_svp_tranx"));
        sizePolicy6.setHeightForWidth(qui_svp_tranx->sizePolicy().hasHeightForWidth());
        qui_svp_tranx->setSizePolicy(sizePolicy6);

        gridLayout17->addWidget(qui_svp_tranx, 1, 0, 1, 1);

        qui_svp_tranz = new QDoubleSpinBox(groupBox_6);
        qui_svp_tranz->setObjectName(QStringLiteral("qui_svp_tranz"));
        sizePolicy6.setHeightForWidth(qui_svp_tranz->sizePolicy().hasHeightForWidth());
        qui_svp_tranz->setSizePolicy(sizePolicy6);

        gridLayout17->addWidget(qui_svp_tranz, 1, 2, 1, 1);

        label_136 = new QLabel(groupBox_6);
        label_136->setObjectName(QStringLiteral("label_136"));

        gridLayout17->addWidget(label_136, 0, 2, 1, 1);

        qui_svp_trany = new QDoubleSpinBox(groupBox_6);
        qui_svp_trany->setObjectName(QStringLiteral("qui_svp_trany"));
        sizePolicy6.setHeightForWidth(qui_svp_trany->sizePolicy().hasHeightForWidth());
        qui_svp_trany->setSizePolicy(sizePolicy6);

        gridLayout17->addWidget(qui_svp_trany, 1, 1, 1, 1);


        vboxLayout13->addLayout(gridLayout17);

        label_132 = new QLabel(groupBox_6);
        label_132->setObjectName(QStringLiteral("label_132"));

        vboxLayout13->addWidget(label_132);

        qui_svp_irotgr = new QComboBox(groupBox_6);
        qui_svp_irotgr->setObjectName(QStringLiteral("qui_svp_irotgr"));

        vboxLayout13->addWidget(qui_svp_irotgr);

        gridLayout18 = new QGridLayout();
        gridLayout18->setObjectName(QStringLiteral("gridLayout18"));
        qui_svp_rotchi = new QDoubleSpinBox(groupBox_6);
        qui_svp_rotchi->setObjectName(QStringLiteral("qui_svp_rotchi"));
        sizePolicy6.setHeightForWidth(qui_svp_rotchi->sizePolicy().hasHeightForWidth());
        qui_svp_rotchi->setSizePolicy(sizePolicy6);

        gridLayout18->addWidget(qui_svp_rotchi, 1, 2, 1, 1);

        label_137 = new QLabel(groupBox_6);
        label_137->setObjectName(QStringLiteral("label_137"));

        gridLayout18->addWidget(label_137, 0, 0, 1, 1);

        qui_svp_rotphi = new QDoubleSpinBox(groupBox_6);
        qui_svp_rotphi->setObjectName(QStringLiteral("qui_svp_rotphi"));
        sizePolicy6.setHeightForWidth(qui_svp_rotphi->sizePolicy().hasHeightForWidth());
        qui_svp_rotphi->setSizePolicy(sizePolicy6);

        gridLayout18->addWidget(qui_svp_rotphi, 1, 1, 1, 1);

        qui_svp_rotthe = new QDoubleSpinBox(groupBox_6);
        qui_svp_rotthe->setObjectName(QStringLiteral("qui_svp_rotthe"));
        sizePolicy6.setHeightForWidth(qui_svp_rotthe->sizePolicy().hasHeightForWidth());
        qui_svp_rotthe->setSizePolicy(sizePolicy6);

        gridLayout18->addWidget(qui_svp_rotthe, 1, 0, 1, 1);

        label_138 = new QLabel(groupBox_6);
        label_138->setObjectName(QStringLiteral("label_138"));

        gridLayout18->addWidget(label_138, 0, 1, 1, 1);

        label_139 = new QLabel(groupBox_6);
        label_139->setObjectName(QStringLiteral("label_139"));

        gridLayout18->addWidget(label_139, 0, 2, 1, 1);


        vboxLayout13->addLayout(gridLayout18);


        vboxLayout11->addWidget(groupBox_6);

        spacerItem51 = new QSpacerItem(20, 16, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vboxLayout11->addItem(spacerItem51);

        advancedOptionsStack->addWidget(AdvancedSVPGrid);
        AdvancedSymmetry = new QWidget();
        AdvancedSymmetry->setObjectName(QStringLiteral("AdvancedSymmetry"));
        vboxLayout14 = new QVBoxLayout(AdvancedSymmetry);
        vboxLayout14->setObjectName(QStringLiteral("vboxLayout14"));
        symmetry_ignore = new QCheckBox(AdvancedSymmetry);
        symmetry_ignore->setObjectName(QStringLiteral("symmetry_ignore"));

        vboxLayout14->addWidget(symmetry_ignore);

        symmetry_integral = new QCheckBox(AdvancedSymmetry);
        symmetry_integral->setObjectName(QStringLiteral("symmetry_integral"));

        vboxLayout14->addWidget(symmetry_integral);

        hboxLayout18 = new QHBoxLayout();
        hboxLayout18->setObjectName(QStringLiteral("hboxLayout18"));
        label_62 = new QLabel(AdvancedSymmetry);
        label_62->setObjectName(QStringLiteral("label_62"));

        hboxLayout18->addWidget(label_62);

        symmetry_tolerance = new QSpinBox(AdvancedSymmetry);
        symmetry_tolerance->setObjectName(QStringLiteral("symmetry_tolerance"));

        hboxLayout18->addWidget(symmetry_tolerance);

        spacerItem52 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout18->addItem(spacerItem52);


        vboxLayout14->addLayout(hboxLayout18);

        label_63 = new QLabel(AdvancedSymmetry);
        label_63->setObjectName(QStringLiteral("label_63"));

        vboxLayout14->addWidget(label_63);

        hboxLayout19 = new QHBoxLayout();
        hboxLayout19->setObjectName(QStringLiteral("hboxLayout19"));
        symmetry_decomposition = new QComboBox(AdvancedSymmetry);
        symmetry_decomposition->setObjectName(QStringLiteral("symmetry_decomposition"));

        hboxLayout19->addWidget(symmetry_decomposition);

        spacerItem53 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout19->addItem(spacerItem53);


        vboxLayout14->addLayout(hboxLayout19);

        spacerItem54 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vboxLayout14->addItem(spacerItem54);

        advancedOptionsStack->addWidget(AdvancedSymmetry);
        AdvancedResources = new QWidget();
        AdvancedResources->setObjectName(QStringLiteral("AdvancedResources"));
        vboxLayout15 = new QVBoxLayout(AdvancedResources);
        vboxLayout15->setObjectName(QStringLiteral("vboxLayout15"));
        gridLayout19 = new QGridLayout();
        gridLayout19->setObjectName(QStringLiteral("gridLayout19"));
        label_26 = new QLabel(AdvancedResources);
        label_26->setObjectName(QStringLiteral("label_26"));

        gridLayout19->addWidget(label_26, 3, 0, 1, 1);

        label_24 = new QLabel(AdvancedResources);
        label_24->setObjectName(QStringLiteral("label_24"));

        gridLayout19->addWidget(label_24, 1, 0, 1, 1);

        max_sub_file_num = new QSpinBox(AdvancedResources);
        max_sub_file_num->setObjectName(QStringLiteral("max_sub_file_num"));

        gridLayout19->addWidget(max_sub_file_num, 4, 1, 1, 1);

        label_25 = new QLabel(AdvancedResources);
        label_25->setObjectName(QStringLiteral("label_25"));

        gridLayout19->addWidget(label_25, 2, 0, 1, 1);

        mem_static = new QSpinBox(AdvancedResources);
        mem_static->setObjectName(QStringLiteral("mem_static"));

        gridLayout19->addWidget(mem_static, 2, 1, 1, 1);

        ao2mo_disk = new QSpinBox(AdvancedResources);
        ao2mo_disk->setObjectName(QStringLiteral("ao2mo_disk"));

        gridLayout19->addWidget(ao2mo_disk, 3, 1, 1, 1);

        label_31 = new QLabel(AdvancedResources);
        label_31->setObjectName(QStringLiteral("label_31"));

        gridLayout19->addWidget(label_31, 4, 0, 1, 1);

        label_23 = new QLabel(AdvancedResources);
        label_23->setObjectName(QStringLiteral("label_23"));

        gridLayout19->addWidget(label_23, 0, 0, 1, 1);

        integrals_buffer = new QSpinBox(AdvancedResources);
        integrals_buffer->setObjectName(QStringLiteral("integrals_buffer"));

        gridLayout19->addWidget(integrals_buffer, 0, 1, 1, 1);

        mem_total = new QSpinBox(AdvancedResources);
        mem_total->setObjectName(QStringLiteral("mem_total"));
        mem_total->setMaximum(9999);

        gridLayout19->addWidget(mem_total, 1, 1, 1, 1);

        spacerItem55 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout19->addItem(spacerItem55, 0, 2, 1, 1);


        vboxLayout15->addLayout(gridLayout19);

        spacerItem56 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vboxLayout15->addItem(spacerItem56);

        advancedOptionsStack->addWidget(AdvancedResources);
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        verticalLayout_50 = new QVBoxLayout(page);
        verticalLayout_50->setObjectName(QStringLiteral("verticalLayout_50"));
        label_16 = new QLabel(page);
        label_16->setObjectName(QStringLiteral("label_16"));

        verticalLayout_50->addWidget(label_16);

        cis_guess_disk = new QCheckBox(page);
        cis_guess_disk->setObjectName(QStringLiteral("cis_guess_disk"));

        verticalLayout_50->addWidget(cis_guess_disk);

        cis_guess_disk_type = new QSpinBox(page);
        cis_guess_disk_type->setObjectName(QStringLiteral("cis_guess_disk_type"));

        verticalLayout_50->addWidget(cis_guess_disk_type);

        verticalSpacer_31 = new QSpacerItem(20, 495, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_50->addItem(verticalSpacer_31);

        advancedOptionsStack->addWidget(page);

        horizontalLayout_17->addWidget(advancedOptionsStack);

        setupTabWidget->addTab(AdvancedTab, QString());

        horizontalLayout_3->addWidget(setupTabWidget);

        previewOutput = new QGroupBox(centralwidget);
        previewOutput->setObjectName(QStringLiteral("previewOutput"));
        sizePolicy.setHeightForWidth(previewOutput->sizePolicy().hasHeightForWidth());
        previewOutput->setSizePolicy(sizePolicy);
        previewOutput->setMinimumSize(QSize(0, 0));
        verticalLayout_18 = new QVBoxLayout(previewOutput);
        verticalLayout_18->setObjectName(QStringLiteral("verticalLayout_18"));
        previewText = new QTextEdit(previewOutput);
        previewText->setObjectName(QStringLiteral("previewText"));
        sizePolicy.setHeightForWidth(previewText->sizePolicy().hasHeightForWidth());
        previewText->setSizePolicy(sizePolicy);
        previewText->setMinimumSize(QSize(0, 0));
        QFont font;
        font.setFamily(QStringLiteral("Courier New"));
        font.setPointSize(12);
        font.setBold(false);
        font.setItalic(false);
        font.setUnderline(false);
        font.setWeight(50);
        font.setStrikeOut(false);
        previewText->setFont(font);

        verticalLayout_18->addWidget(previewText);

        hboxLayout20 = new QHBoxLayout();
        hboxLayout20->setObjectName(QStringLiteral("hboxLayout20"));
        spacerItem57 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout20->addItem(spacerItem57);

        label_5 = new QLabel(previewOutput);
        label_5->setObjectName(QStringLiteral("label_5"));

        hboxLayout20->addWidget(label_5);

        serverCombo = new QComboBox(previewOutput);
        serverCombo->setObjectName(QStringLiteral("serverCombo"));

        hboxLayout20->addWidget(serverCombo);


        verticalLayout_18->addLayout(hboxLayout20);

        hboxLayout21 = new QHBoxLayout();
        hboxLayout21->setObjectName(QStringLiteral("hboxLayout21"));
        resetButton = new QPushButton(previewOutput);
        resetButton->setObjectName(QStringLiteral("resetButton"));

        hboxLayout21->addWidget(resetButton);

        spacerItem58 = new QSpacerItem(40, 20, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);

        hboxLayout21->addItem(spacerItem58);

        cancelButton = new QPushButton(previewOutput);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));

        hboxLayout21->addWidget(cancelButton);

        submitButton = new QPushButton(previewOutput);
        submitButton->setObjectName(QStringLiteral("submitButton"));
        submitButton->setAutoDefault(true);

        hboxLayout21->addWidget(submitButton);


        verticalLayout_18->addLayout(hboxLayout21);


        horizontalLayout_3->addWidget(previewOutput);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1306, 21));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);
#ifndef QT_NO_SHORTCUT
        label_exchange->setBuddy(exchange);
        label_106->setBuddy(jobList);
        label_job_type->setBuddy(job_type);
        label_method->setBuddy(method);
        label_basis->setBuddy(basis);
        label_ecp->setBuddy(ecp);
        label_correlation->setBuddy(correlation);
        label_qui_multiplicity->setBuddy(qui_multiplicity);
        label_qui_charge->setBuddy(qui_charge);
        label_209->setBuddy(scf_guess);
        label_scf_guess_mix->setBuddy(scf_guess_mix);
        label_145->setBuddy(basis2);
        label_18->setBuddy(scf_max_cycles);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(serverCombo, submitButton);
        QWidget::setTabOrder(submitButton, exchange);
        QWidget::setTabOrder(exchange, deleteJobButton);
        QWidget::setTabOrder(deleteJobButton, addJobButton);
        QWidget::setTabOrder(addJobButton, previewText);
        QWidget::setTabOrder(previewText, resetButton);
        QWidget::setTabOrder(resetButton, geom_opt_tol_gradient);
        QWidget::setTabOrder(geom_opt_tol_gradient, dscf_convergence_level_2);
        QWidget::setTabOrder(dscf_convergence_level_2, dscf_max_cycles_level_2);
        QWidget::setTabOrder(dscf_max_cycles_level_2, dscf_max_cycles_level_1);
        QWidget::setTabOrder(dscf_max_cycles_level_1, dscf_convergence_level_1);
        QWidget::setTabOrder(dscf_convergence_level_1, moprop_max_cycles_level_1);
        QWidget::setTabOrder(moprop_max_cycles_level_1, moprop_max_cycles_level_2);
        QWidget::setTabOrder(moprop_max_cycles_level_2, moprop_convergence_level_1);
        QWidget::setTabOrder(moprop_convergence_level_1, moprop_convergence_level_2);
        QWidget::setTabOrder(moprop_convergence_level_2, advancedOptionsTree);
        QWidget::setTabOrder(advancedOptionsTree, diis_switch_thresh);
        QWidget::setTabOrder(diis_switch_thresh, diis_print);
        QWidget::setTabOrder(diis_print, diis_max_cycles);
        QWidget::setTabOrder(diis_max_cycles, diis_subspace_size);
        QWidget::setTabOrder(diis_subspace_size, diis_error_metric);
        QWidget::setTabOrder(diis_error_metric, scf_final_print);
        QWidget::setTabOrder(scf_final_print, print_distance_matrix);
        QWidget::setTabOrder(print_distance_matrix, scf_print);
        QWidget::setTabOrder(scf_print, scf_guess_print);
        QWidget::setTabOrder(scf_guess_print, print_orbitals);
        QWidget::setTabOrder(print_orbitals, qui_print_orbitals);
        QWidget::setTabOrder(qui_print_orbitals, print_general_basis);
        QWidget::setTabOrder(print_general_basis, scf_print_frgm);
        QWidget::setTabOrder(scf_print_frgm, basis_linear_dependence_thresh);
        QWidget::setTabOrder(basis_linear_dependence_thresh, thresh);
        QWidget::setTabOrder(thresh, multipole_order);
        QWidget::setTabOrder(multipole_order, qui_plots_points);
        QWidget::setTabOrder(qui_plots_points, skip_cis_rpa);
        QWidget::setTabOrder(skip_cis_rpa, qui_use_case);
        QWidget::setTabOrder(qui_use_case, ftc_fast);
        QWidget::setTabOrder(ftc_fast, ftc_class_thresh_mult);
        QWidget::setTabOrder(ftc_class_thresh_mult, ftc_class_thresh_order);
        QWidget::setTabOrder(ftc_class_thresh_order, epao_weights);
        QWidget::setTabOrder(epao_weights, pao_method);
        QWidget::setTabOrder(pao_method, pao_algorithm);
        QWidget::setTabOrder(pao_algorithm, epao_iterate);
        QWidget::setTabOrder(epao_iterate, geom_opt_hessian_update);
        QWidget::setTabOrder(geom_opt_hessian_update, geom_opt_coordinates);
        QWidget::setTabOrder(geom_opt_coordinates, geom_opt_hessian);
        QWidget::setTabOrder(geom_opt_hessian, qui_geom_opt_fallback);
        QWidget::setTabOrder(qui_geom_opt_fallback, geom_opt_diis_subspace);
        QWidget::setTabOrder(geom_opt_diis_subspace, geom_opt_print);
        QWidget::setTabOrder(geom_opt_print, geom_opt_scf_guess_always);
        QWidget::setTabOrder(geom_opt_scf_guess_always, geom_print);
        QWidget::setTabOrder(geom_print, vibman_print);
        QWidget::setTabOrder(vibman_print, analytic_derivative_order);
        QWidget::setTabOrder(analytic_derivative_order, fd_step_size);
        QWidget::setTabOrder(fd_step_size, aimd_moments);
        QWidget::setTabOrder(aimd_moments, aimd_fock_extrapolation_order);
        QWidget::setTabOrder(aimd_fock_extrapolation_order, aimd_fock_extrapolation_points);
        QWidget::setTabOrder(aimd_fock_extrapolation_points, qmmm);
        QWidget::setTabOrder(qmmm, qmmm_charges);
        QWidget::setTabOrder(qmmm_charges, readChargesButton);
        QWidget::setTabOrder(readChargesButton, cis_max_cycles);
        QWidget::setTabOrder(cis_max_cycles, cis_convergence);
        QWidget::setTabOrder(cis_convergence, symmetry_ignore);
        QWidget::setTabOrder(symmetry_ignore, symmetry_integral);
        QWidget::setTabOrder(symmetry_integral, symmetry_tolerance);
        QWidget::setTabOrder(symmetry_tolerance, symmetry_decomposition);
        QWidget::setTabOrder(symmetry_decomposition, max_sub_file_num);
        QWidget::setTabOrder(max_sub_file_num, mem_static);
        QWidget::setTabOrder(mem_static, ao2mo_disk);
        QWidget::setTabOrder(ao2mo_disk, integrals_buffer);
        QWidget::setTabOrder(integrals_buffer, mem_total);
        QWidget::setTabOrder(mem_total, qui_chemsol_ngrids);
        QWidget::setTabOrder(qui_chemsol_ngrids, qui_chemsol_print);
        QWidget::setTabOrder(qui_chemsol_print, qui_svp_nptleb);
        QWidget::setTabOrder(qui_svp_nptleb, qui_svp_intcav);
        QWidget::setTabOrder(qui_svp_intcav, qui_svp_nptthe);
        QWidget::setTabOrder(qui_svp_nptthe, qui_svp_nptphi);
        QWidget::setTabOrder(qui_svp_nptphi, qui_svp_itrngr);
        QWidget::setTabOrder(qui_svp_itrngr, qui_svp_tranx);
        QWidget::setTabOrder(qui_svp_tranx, qui_svp_tranz);
        QWidget::setTabOrder(qui_svp_tranz, qui_svp_trany);
        QWidget::setTabOrder(qui_svp_trany, qui_svp_irotgr);
        QWidget::setTabOrder(qui_svp_irotgr, qui_svp_rotchi);
        QWidget::setTabOrder(qui_svp_rotchi, qui_svp_rotphi);
        QWidget::setTabOrder(qui_svp_rotphi, qui_svp_rotthe);
        QWidget::setTabOrder(qui_svp_rotthe, geom_opt_tol_displacement);
        QWidget::setTabOrder(geom_opt_tol_displacement, setupTabWidget);
        QWidget::setTabOrder(setupTabWidget, pdb_print);
        QWidget::setTabOrder(pdb_print, geom_opt_iproj);
        QWidget::setTabOrder(geom_opt_iproj, gaussian_blur);
        QWidget::setTabOrder(gaussian_blur, link_atom_projection);
        QWidget::setTabOrder(link_atom_projection, qmmm_full_hessian);
        QWidget::setTabOrder(qmmm_full_hessian, geom_opt_tol_energy);
        QWidget::setTabOrder(geom_opt_tol_energy, cancelButton);
        QWidget::setTabOrder(cancelButton, meteco);
        QWidget::setTabOrder(meteco, efp);
        QWidget::setTabOrder(efp, efp_fragments_only);
        QWidget::setTabOrder(efp_fragments_only, efp_input);
        QWidget::setTabOrder(efp_input, cc_dov_thresh);
        QWidget::setTabOrder(cc_dov_thresh, xopt_state_1);
        QWidget::setTabOrder(xopt_state_1, xopt_state_2);
        QWidget::setTabOrder(xopt_state_2, xopt_seam_only);
        QWidget::setTabOrder(xopt_seam_only, qui_svp_memory);
        QWidget::setTabOrder(qui_svp_memory, qui_svp_cavity_conv);
        QWidget::setTabOrder(qui_svp_cavity_conv, qui_svp_charge_conv);
        QWidget::setTabOrder(qui_svp_charge_conv, qui_svp_guess);
        QWidget::setTabOrder(qui_svp_guess, qui_svp_path);
        QWidget::setTabOrder(qui_svp_path, qui_pcm_printlevel);

        menubar->addAction(menuFile->menuAction());
        menuFile->addAction(actionNew_Input_Section);
        menuFile->addAction(actionRead_Input);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSave_As);
        menuFile->addAction(actionEdit_Preferences);

        retranslateUi(MainWindow);
        QObject::connect(cancelButton, SIGNAL(clicked(bool)), MainWindow, SLOT(close()));

        setupTabWidget->setCurrentIndex(0);
        toolBoxOptions->setCurrentIndex(0);
        toolBoxOptions->layout()->setSpacing(11);
        advancedOptionsStack->setCurrentIndex(3);
        largeMoleculesStack->setCurrentIndex(0);
        solventStack->setCurrentIndex(2);
        submitButton->setDefault(true);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        actionAbout_QUI->setText(QApplication::translate("MainWindow", "New input section", Q_NULLPTR));
        action->setText(QApplication::translate("MainWindow", "Read XYZ Input", Q_NULLPTR));
        actionNew_Input_Section->setText(QApplication::translate("MainWindow", "New Input Section", Q_NULLPTR));
        actionRead_Input->setText(QApplication::translate("MainWindow", "Read Input", Q_NULLPTR));
        actionSave->setText(QApplication::translate("MainWindow", "Save", Q_NULLPTR));
        actionSave_As->setText(QApplication::translate("MainWindow", "Save As", Q_NULLPTR));
        actionEdit_Preferences->setText(QApplication::translate("MainWindow", "Edit Preferences", Q_NULLPTR));
        label_exchange->setText(QApplication::translate("MainWindow", "Exchange", Q_NULLPTR));
        label_106->setText(QApplication::translate("MainWindow", "Job Section", Q_NULLPTR));
        label_job_type->setText(QApplication::translate("MainWindow", "Calculate", Q_NULLPTR));
        label_method->setText(QApplication::translate("MainWindow", "Method", Q_NULLPTR));
        label_basis->setText(QApplication::translate("MainWindow", "Basis", Q_NULLPTR));
        label_ecp->setText(QApplication::translate("MainWindow", "ECP", Q_NULLPTR));
        label_correlation->setText(QApplication::translate("MainWindow", "Correlation", Q_NULLPTR));
        label_qui_multiplicity->setText(QApplication::translate("MainWindow", "Multiplicity", Q_NULLPTR));
        label_qui_charge->setText(QApplication::translate("MainWindow", "Charge", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        addJobButton->setToolTip(QApplication::translate("MainWindow", "Add section to input file", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        addJobButton->setStyleSheet(QApplication::translate("MainWindow", "QToolButton {\n"
"   color: #333;\n"
"   background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, \n"
"          stop: 0 #fff,\n"
"          stop: 0.5 #eee, \n"
"          stop: 1 #999);\n"
"   border-width: 2px;\n"
"   border-color: #333;\n"
"   border-style: solid;\n"
"   border-radius: 5;\n"
"   padding: 0px;\n"
"   font-size: 24px;\n"
"   min-width: 24px;\n"
"   max-width: 24px;\n"
"   min-height: 24px;\n"
"   max-height: 24px;\n"
"}\n"
"\n"
"QToolButton:disabled {\n"
"  background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, \n"
"          stop: 0 #fff,\n"
"          stop: 0.5 #eee, \n"
"          stop: 1 #bbb);\n"
"   border-color: #aaa;\n"
"   color: #aaa;\n"
"}\n"
"\n"
"QToolButton:pressed {\n"
"   border-color: #222;\n"
"}\n"
"\n"
"QToolButton:checked {\n"
"   border-color: #b00;\n"
"}", Q_NULLPTR));
        addJobButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        deleteJobButton->setToolTip(QApplication::translate("MainWindow", "Remove current section from input file", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        deleteJobButton->setStyleSheet(QApplication::translate("MainWindow", "QToolButton {\n"
"   color: #333;\n"
"   background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, \n"
"          stop: 0 #fff,\n"
"          stop: 0.5 #eee, \n"
"          stop: 1 #999);\n"
"   border-width: 2px;\n"
"   border-color: #333;\n"
"   border-style: solid;\n"
"   border-radius: 5;\n"
"   padding: 0px;\n"
"   font-size: 24px;\n"
"   min-width: 24px;\n"
"   max-width: 24px;\n"
"   min-height: 24px;\n"
"   max-height: 24px;\n"
"}\n"
"\n"
"QToolButton:disabled {\n"
"  background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, \n"
"          stop: 0 #fff,\n"
"          stop: 0.5 #eee, \n"
"          stop: 1 #bbb);\n"
"   border-color: #aaa;\n"
"   color: #aaa;\n"
"}\n"
"\n"
"QToolButton:pressed {\n"
"   border-color: #222;\n"
"}\n"
"\n"
"\n"
"QToolButton:checked {\n"
"   border-color: #b00;\n"
"}", Q_NULLPTR));
        deleteJobButton->setText(QString());
        editJobSectionButton->setText(QApplication::translate("MainWindow", "Edit", Q_NULLPTR));
        scf_guess_mix->setSuffix(QApplication::translate("MainWindow", " %", Q_NULLPTR));
        label_209->setText(QApplication::translate("MainWindow", "Guess", Q_NULLPTR));
        label_39->setText(QApplication::translate("MainWindow", "Convergence", Q_NULLPTR));
        complex->setText(QApplication::translate("MainWindow", "Complex SCF", Q_NULLPTR));
        label_scf_guess_mix->setText(QApplication::translate("MainWindow", "Guess Mix", Q_NULLPTR));
        label_145->setText(QApplication::translate("MainWindow", "Second Basis", Q_NULLPTR));
        ghf->setText(QApplication::translate("MainWindow", "Generalized Hartree-Fock", Q_NULLPTR));
        label_210->setText(QApplication::translate("MainWindow", "Algorithm", Q_NULLPTR));
        os_roscf->setText(QApplication::translate("MainWindow", "Open-shell Singlet ROSCF", Q_NULLPTR));
        dual_basis_energy->setText(QApplication::translate("MainWindow", "Dual Basis Energy", Q_NULLPTR));
        label_18->setText(QApplication::translate("MainWindow", "Max Cycles", Q_NULLPTR));
        gen_scfman->setText(QApplication::translate("MainWindow", "Use GEN_SCFMAN", Q_NULLPTR));
        complex_mix->setSuffix(QApplication::translate("MainWindow", " %", Q_NULLPTR));
        label_complex_mix->setText(QApplication::translate("MainWindow", "Complex Mix", Q_NULLPTR));
        internal_stability->setText(QApplication::translate("MainWindow", "Stability Analysis", Q_NULLPTR));
        unrestricted->setText(QApplication::translate("MainWindow", "Unrestricted", Q_NULLPTR));
        toolBoxOptions->setItemText(toolBoxOptions->indexOf(pageScfControl), QApplication::translate("MainWindow", "SCF Control", Q_NULLPTR));
        gui->setText(QApplication::translate("MainWindow", "Generate Checkpoint File", Q_NULLPTR));
        chelpg->setText(QApplication::translate("MainWindow", "CHELPG Charges", Q_NULLPTR));
        nbo->setText(QApplication::translate("MainWindow", "NBO Analysis", Q_NULLPTR));
        toolBoxOptions->setItemText(toolBoxOptions->indexOf(pageWavefunctionAnalysis), QApplication::translate("MainWindow", "Wavefunction Analysis", Q_NULLPTR));
        setupTabWidget->setTabText(setupTabWidget->indexOf(SetupTab), QApplication::translate("MainWindow", "Setup", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem = advancedOptionsTree->headerItem();
        ___qtreewidgetitem->setText(0, QApplication::translate("MainWindow", "Category", Q_NULLPTR));

        const bool __sortingEnabled = advancedOptionsTree->isSortingEnabled();
        advancedOptionsTree->setSortingEnabled(false);
        QTreeWidgetItem *___qtreewidgetitem1 = advancedOptionsTree->topLevelItem(0);
        ___qtreewidgetitem1->setText(0, QApplication::translate("MainWindow", "SCF Control", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem2 = ___qtreewidgetitem1->child(0);
        ___qtreewidgetitem2->setText(0, QApplication::translate("MainWindow", "DIIS", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem3 = ___qtreewidgetitem1->child(1);
        ___qtreewidgetitem3->setText(0, QApplication::translate("MainWindow", "Large Molecule Methods", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem4 = ___qtreewidgetitem1->child(2);
        ___qtreewidgetitem4->setText(0, QApplication::translate("MainWindow", "Print Options", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem5 = ___qtreewidgetitem1->child(3);
        ___qtreewidgetitem5->setText(0, QApplication::translate("MainWindow", "HFPT", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem6 = ___qtreewidgetitem1->child(4);
        ___qtreewidgetitem6->setText(0, QApplication::translate("MainWindow", "PAO", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem7 = ___qtreewidgetitem1->child(5);
        ___qtreewidgetitem7->setText(0, QApplication::translate("MainWindow", "Internal Stability", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem8 = ___qtreewidgetitem1->child(6);
        ___qtreewidgetitem8->setText(0, QApplication::translate("MainWindow", "Thresholds", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem9 = advancedOptionsTree->topLevelItem(1);
        ___qtreewidgetitem9->setText(0, QApplication::translate("MainWindow", "DFT", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem10 = ___qtreewidgetitem9->child(0);
        ___qtreewidgetitem10->setText(0, QApplication::translate("MainWindow", "Dispersion Correction", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem11 = ___qtreewidgetitem9->child(1);
        ___qtreewidgetitem11->setText(0, QApplication::translate("MainWindow", "XDM", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem12 = ___qtreewidgetitem9->child(2);
        ___qtreewidgetitem12->setText(0, QApplication::translate("MainWindow", "Nonlocal Correlation", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem13 = advancedOptionsTree->topLevelItem(2);
        ___qtreewidgetitem13->setText(0, QApplication::translate("MainWindow", "Post Hartree Fock", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem14 = ___qtreewidgetitem13->child(0);
        ___qtreewidgetitem14->setText(0, QApplication::translate("MainWindow", "Coupled Cluster", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem15 = advancedOptionsTree->topLevelItem(3);
        ___qtreewidgetitem15->setText(0, QApplication::translate("MainWindow", "Excited States", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem16 = ___qtreewidgetitem15->child(0);
        ___qtreewidgetitem16->setText(0, QApplication::translate("MainWindow", "CIS", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem17 = ___qtreewidgetitem15->child(1);
        ___qtreewidgetitem17->setText(0, QApplication::translate("MainWindow", "ROKS", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem18 = ___qtreewidgetitem15->child(2);
        ___qtreewidgetitem18->setText(0, QApplication::translate("MainWindow", "EOM", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem19 = ___qtreewidgetitem18->child(0);
        ___qtreewidgetitem19->setText(0, QApplication::translate("MainWindow", "Surface Crossing", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem20 = ___qtreewidgetitem15->child(3);
        ___qtreewidgetitem20->setText(0, QApplication::translate("MainWindow", "ADC", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem21 = advancedOptionsTree->topLevelItem(4);
        ___qtreewidgetitem21->setText(0, QApplication::translate("MainWindow", "Wavefunction Analysis", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem22 = ___qtreewidgetitem21->child(0);
        ___qtreewidgetitem22->setText(0, QApplication::translate("MainWindow", "Plots", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem23 = ___qtreewidgetitem21->child(1);
        ___qtreewidgetitem23->setText(0, QApplication::translate("MainWindow", "Molecular Properties", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem24 = advancedOptionsTree->topLevelItem(5);
        ___qtreewidgetitem24->setText(0, QApplication::translate("MainWindow", "Geometry Optimization", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem25 = ___qtreewidgetitem24->child(0);
        ___qtreewidgetitem25->setText(0, QApplication::translate("MainWindow", "Opt Thresholds", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem26 = advancedOptionsTree->topLevelItem(6);
        ___qtreewidgetitem26->setText(0, QApplication::translate("MainWindow", "Reaction Pathway", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem27 = advancedOptionsTree->topLevelItem(7);
        ___qtreewidgetitem27->setText(0, QApplication::translate("MainWindow", "Frequencies", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem28 = advancedOptionsTree->topLevelItem(8);
        ___qtreewidgetitem28->setText(0, QApplication::translate("MainWindow", "Molecular Dynamics", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem29 = advancedOptionsTree->topLevelItem(9);
        ___qtreewidgetitem29->setText(0, QApplication::translate("MainWindow", "EFP Options", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem30 = advancedOptionsTree->topLevelItem(10);
        ___qtreewidgetitem30->setText(0, QApplication::translate("MainWindow", "QMMM", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem31 = advancedOptionsTree->topLevelItem(11);
        ___qtreewidgetitem31->setText(0, QApplication::translate("MainWindow", "NMR Chemical Shifts", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem32 = advancedOptionsTree->topLevelItem(12);
        ___qtreewidgetitem32->setText(0, QApplication::translate("MainWindow", "Solvent Model", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem33 = advancedOptionsTree->topLevelItem(13);
        ___qtreewidgetitem33->setText(0, QApplication::translate("MainWindow", "Symmetry", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem34 = advancedOptionsTree->topLevelItem(14);
        ___qtreewidgetitem34->setText(0, QApplication::translate("MainWindow", "Resources", Q_NULLPTR));
        advancedOptionsTree->setSortingEnabled(__sortingEnabled);

        label_203->setText(QApplication::translate("MainWindow", "Basis Projection", Q_NULLPTR));
        qui_section_swap_occupied_virtual->setText(QApplication::translate("MainWindow", "Swap Orbitals", Q_NULLPTR));
        label_199->setText(QApplication::translate("MainWindow", "Incremental Fock", Q_NULLPTR));
        label_85->setText(QApplication::translate("MainWindow", "RCA Print Level", Q_NULLPTR));
        label_101->setText(QApplication::translate("MainWindow", "RCA Switch Thresh", Q_NULLPTR));
        label_202->setText(QApplication::translate("MainWindow", "Pure/Cartesian", Q_NULLPTR));
        label_200->setText(QApplication::translate("MainWindow", "MOM Start Cycle", Q_NULLPTR));
        label_117->setText(QApplication::translate("MainWindow", "MOM Method", Q_NULLPTR));
        label_201->setText(QApplication::translate("MainWindow", "Max RCA Cycles", Q_NULLPTR));
        pseudo_canonical->setText(QApplication::translate("MainWindow", "Use Canonical Steps", Q_NULLPTR));
        direct_scf->setText(QApplication::translate("MainWindow", "Direct SCF", Q_NULLPTR));
        label_34->setText(QApplication::translate("MainWindow", "Subspace", Q_NULLPTR));
        label_41->setText(QApplication::translate("MainWindow", "Max DIIS Cycles", Q_NULLPTR));
        label_94->setText(QApplication::translate("MainWindow", "DIIS Metric", Q_NULLPTR));
        label_35->setText(QApplication::translate("MainWindow", "Print Level", Q_NULLPTR));
        label_36->setText(QApplication::translate("MainWindow", "Threshold", Q_NULLPTR));
        label_print_orbitals->setText(QApplication::translate("MainWindow", "Number of Virtuals", Q_NULLPTR));
        qui_print_orbitals->setText(QApplication::translate("MainWindow", "Print Orbitals", Q_NULLPTR));
        label_30->setText(QApplication::translate("MainWindow", "SCF Guess Print", Q_NULLPTR));
        label_29->setText(QApplication::translate("MainWindow", "SCF Print", Q_NULLPTR));
        label_43->setText(QApplication::translate("MainWindow", "SCF Final Print", Q_NULLPTR));
        label_105->setText(QApplication::translate("MainWindow", "Distance Matrix", Q_NULLPTR));
        label_21->setText(QApplication::translate("MainWindow", "PDB Coordinates", Q_NULLPTR));
        print_general_basis->setText(QApplication::translate("MainWindow", "Print General Basis", Q_NULLPTR));
        scf_print_frgm->setText(QApplication::translate("MainWindow", "Print Fragments", Q_NULLPTR));
        label_89->setText(QApplication::translate("MainWindow", "WFN filename:", Q_NULLPTR));
        groupBox_0->setTitle(QApplication::translate("MainWindow", "Method", Q_NULLPTR));
        qui_use_case->setText(QApplication::translate("MainWindow", "CASE", Q_NULLPTR));
        qui_cfmm->setText(QApplication::translate("MainWindow", "CFMM", Q_NULLPTR));
        qui_none->setText(QApplication::translate("MainWindow", "None", Q_NULLPTR));
        qui_use_ri->setText(QApplication::translate("MainWindow", "RI", Q_NULLPTR));
        ftc->setText(QApplication::translate("MainWindow", "FTC", Q_NULLPTR));
        label_47->setText(QApplication::translate("MainWindow", "CFMM Grain", Q_NULLPTR));
        label_46->setText(QApplication::translate("MainWindow", "Multipole Order", Q_NULLPTR));
        lin_k->setText(QApplication::translate("MainWindow", "Use Lin K", Q_NULLPTR));
        ftc_fast->setText(QApplication::translate("MainWindow", "Increase Speed (and memory)", Q_NULLPTR));
        label_99->setText(QApplication::translate("MainWindow", "Cutoff Threshold:", Q_NULLPTR));
        label_100->setText(QApplication::translate("MainWindow", "x10 e-", Q_NULLPTR));
        checkBox_3->setText(QApplication::translate("MainWindow", "ARI", Q_NULLPTR));
        label_77->setText(QApplication::translate("MainWindow", "Outer Radius", Q_NULLPTR));
        checkBox_2->setText(QApplication::translate("MainWindow", "RI-K", Q_NULLPTR));
        label_55->setText(QApplication::translate("MainWindow", "Inner Radius", Q_NULLPTR));
        checkBox->setText(QApplication::translate("MainWindow", "RI-J", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "HFPT Basis", Q_NULLPTR));
        label_dfpt_xc_grid->setText(QApplication::translate("MainWindow", "DFPT Grid", Q_NULLPTR));
        label_dfpt_exchange->setText(QApplication::translate("MainWindow", "DFPT Exchange", Q_NULLPTR));
        label_49->setText(QApplication::translate("MainWindow", "EPAO Weights", Q_NULLPTR));
        label_50->setText(QApplication::translate("MainWindow", "PAO Algorithm", Q_NULLPTR));
        label_48->setText(QApplication::translate("MainWindow", "Iterations", Q_NULLPTR));
        label_51->setText(QApplication::translate("MainWindow", "PAO Method", Q_NULLPTR));
        label_67->setText(QApplication::translate("MainWindow", "Convergence", Q_NULLPTR));
        label_61->setText(QApplication::translate("MainWindow", "Davidson Iterations", Q_NULLPTR));
        label_57->setText(QApplication::translate("MainWindow", "Max SCFs", Q_NULLPTR));
        label_69->setText(QApplication::translate("MainWindow", "Number of Roots", Q_NULLPTR));
        fd_mat_vec_prod->setText(QApplication::translate("MainWindow", "Compute Vec-Mat Poduct By FD", Q_NULLPTR));
        label_32->setText(QApplication::translate("MainWindow", "Linear Dependence", Q_NULLPTR));
        label_40->setText(QApplication::translate("MainWindow", "Integrals Thresh", Q_NULLPTR));
        label_211->setText(QApplication::translate("MainWindow", "Shell Pair Criterion:", Q_NULLPTR));
        label_198->setText(QApplication::translate("MainWindow", "Variable Thresh", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Grid", Q_NULLPTR));
        xc_smart_grid->setText(QApplication::translate("MainWindow", "Use Smart Grid", Q_NULLPTR));
        fast_xc->setText(QApplication::translate("MainWindow", "Fast XC", Q_NULLPTR));
        incdft->setText(QApplication::translate("MainWindow", "Incremental DFT", Q_NULLPTR));
        mrxc->setText(QApplication::translate("MainWindow", "Multi-resolution XC", Q_NULLPTR));
        groupBox_mrxc->setTitle(QApplication::translate("MainWindow", "MRXC Options", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "Smoothness Precision:", Q_NULLPTR));
        label_102->setText(QApplication::translate("MainWindow", "x10 e-", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "Interpolation Order", Q_NULLPTR));
        label_76->setText(QApplication::translate("MainWindow", "Model", Q_NULLPTR));
        label_98->setText(QApplication::translate("MainWindow", "Strength", Q_NULLPTR));
        groupBox_dft_d->setTitle(QApplication::translate("MainWindow", "DFT-D3", Q_NULLPTR));
        label_9->setText(QApplication::translate("MainWindow", "S<sub>6</sub>", Q_NULLPTR));
        label_19->setText(QApplication::translate("MainWindow", "S<sub>r6</sub>", Q_NULLPTR));
        label_20->setText(QApplication::translate("MainWindow", "S<sub>8</sub>", Q_NULLPTR));
        dft_d3_3body->setText(QApplication::translate("MainWindow", "3-Body interactions", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "XDM", Q_NULLPTR));
        label_dftvdw_method->setText(QApplication::translate("MainWindow", "Method", Q_NULLPTR));
        label_dftvdw_print->setText(QApplication::translate("MainWindow", "Print", Q_NULLPTR));
        label_dftvdw_mol1natoms->setText(QApplication::translate("MainWindow", "Atoms", Q_NULLPTR));
        label_dftvdw_kai->setText(QApplication::translate("MainWindow", "K", Q_NULLPTR));
        label_dftvdw_alpha1->setText(QApplication::translate("MainWindow", "&alpha;1", Q_NULLPTR));
        label_dftvdw_alpha2->setText(QApplication::translate("MainWindow", "&alpha;2", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "Grid", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "Functional", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Frozen Core", Q_NULLPTR));
        qui_frozen_core->setText(QApplication::translate("MainWindow", "Use Frozen Core", Q_NULLPTR));
        label_93->setText(QApplication::translate("MainWindow", "Core Print", Q_NULLPTR));
        label_234->setText(QApplication::translate("MainWindow", "Frozen Virtual Orbs", Q_NULLPTR));
        label_123->setText(QApplication::translate("MainWindow", "Frozen Core Orbs", Q_NULLPTR));
        label_92->setText(QApplication::translate("MainWindow", "Core Character", Q_NULLPTR));
        ssg->setText(QApplication::translate("MainWindow", "Compute SSG Wavefunction", Q_NULLPTR));
        mp2v->setText(QApplication::translate("MainWindow", "MP2[V]", Q_NULLPTR));
        label_28->setText(QApplication::translate("MainWindow", "MP2 Algorithm", Q_NULLPTR));
        label_133->setText(QApplication::translate("MainWindow", "Max Iterations", Q_NULLPTR));
        label_224->setText(QApplication::translate("MainWindow", "Convergence", Q_NULLPTR));
        label_151->setText(QApplication::translate("MainWindow", "DIIS Method", Q_NULLPTR));
        label_155->setText(QApplication::translate("MainWindow", "DIIS Start", Q_NULLPTR));
        label_152->setText(QApplication::translate("MainWindow", "Denominator Thresh", Q_NULLPTR));
        label_227->setText(QApplication::translate("MainWindow", "Print Level", Q_NULLPTR));
        label_104->setText(QApplication::translate("MainWindow", "Cholesky Tolerance", Q_NULLPTR));
        ccman2->setText(QApplication::translate("MainWindow", "CCMAN2", Q_NULLPTR));
        cc_ref_prop->setText(QApplication::translate("MainWindow", "Reference properties", Q_NULLPTR));
        cc_ref_prop_te->setText(QApplication::translate("MainWindow", "Two-electron properties", Q_NULLPTR));
        cc_fullresponse->setText(QApplication::translate("MainWindow", "Include Orbital Relaxation", Q_NULLPTR));
        direct_ri->setText(QApplication::translate("MainWindow", "Direct RI", Q_NULLPTR));
        label_226->setText(QApplication::translate("MainWindow", "CC Memory", Q_NULLPTR));
        label_115->setText(QApplication::translate("MainWindow", "Threads", Q_NULLPTR));
        cc_symmetry->setText(QApplication::translate("MainWindow", "Symmetry", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "CIS", Q_NULLPTR));
        label_166->setText(QApplication::translate("MainWindow", "Max Cycles", Q_NULLPTR));
        label_22->setText(QApplication::translate("MainWindow", "Max Subspace", Q_NULLPTR));
        label_66->setText(QApplication::translate("MainWindow", "Convergence", Q_NULLPTR));
        label_90->setText(QApplication::translate("MainWindow", "Guess Type", Q_NULLPTR));
        cis_dynamic_mem->setText(QApplication::translate("MainWindow", "Use Dynamic Memory", Q_NULLPTR));
        groupBox_10->setTitle(QApplication::translate("MainWindow", "Reduced Active Space", Q_NULLPTR));
        label_cis_ras_cutoff_virtual->setText(QApplication::translate("MainWindow", "Virtual Cutoff", Q_NULLPTR));
        label_cis_ras_cutoff_occupied->setText(QApplication::translate("MainWindow", "Occupied Cutoff", Q_NULLPTR));
        label_cis_ras_type->setText(QApplication::translate("MainWindow", "Subspace", Q_NULLPTR));
        cis_ras->setText(QApplication::translate("MainWindow", "Use Reduced Active Space", Q_NULLPTR));
        cis_ras_print->setText(QApplication::translate("MainWindow", "Increase Printout", Q_NULLPTR));
        roks->setText(QApplication::translate("MainWindow", "Restricted Open-Shell Kohn-Sham", Q_NULLPTR));
        label_27->setText(QApplication::translate("MainWindow", "Level Shift", Q_NULLPTR));
        label_188->setText(QApplication::translate("MainWindow", "Correlation", Q_NULLPTR));
        groupBox_17->setTitle(QApplication::translate("MainWindow", "Guess Options", Q_NULLPTR));
        label_195->setText(QApplication::translate("MainWindow", "Singles Guess Vectors", Q_NULLPTR));
        label_196->setText(QApplication::translate("MainWindow", "Doubles Guess Vectors", Q_NULLPTR));
        groupBox_14->setTitle(QApplication::translate("MainWindow", "Davidson Options", Q_NULLPTR));
        label_215->setText(QApplication::translate("MainWindow", "Convergence", Q_NULLPTR));
        label_162->setText(QApplication::translate("MainWindow", "Max Vectors", Q_NULLPTR));
        label_167->setText(QApplication::translate("MainWindow", "Max iterations", Q_NULLPTR));
        label_216->setText(QApplication::translate("MainWindow", "Threshold", Q_NULLPTR));
        adc_guess->setTitle(QApplication::translate("MainWindow", "Guess Options", Q_NULLPTR));
        label_197->setText(QApplication::translate("MainWindow", "Singles Guess Vectors", Q_NULLPTR));
        label_204->setText(QApplication::translate("MainWindow", "Doubles Guess Vectors", Q_NULLPTR));
        adc_davidson->setTitle(QApplication::translate("MainWindow", "Davidson Options", Q_NULLPTR));
        label_217->setText(QApplication::translate("MainWindow", "Convergence", Q_NULLPTR));
        label_163->setText(QApplication::translate("MainWindow", "Max. Subspace", Q_NULLPTR));
        label_168->setText(QApplication::translate("MainWindow", "Max. Iterations", Q_NULLPTR));
        label_218->setText(QApplication::translate("MainWindow", "Threshold", Q_NULLPTR));
        adc_diis->setTitle(QApplication::translate("MainWindow", "DIIS Options", Q_NULLPTR));
        label_42->setText(QApplication::translate("MainWindow", "Res. Convergence", Q_NULLPTR));
        label_177->setText(QApplication::translate("MainWindow", "Max. Iterations", Q_NULLPTR));
        label_219->setText(QApplication::translate("MainWindow", "Energy Convergence", Q_NULLPTR));
        label_164->setText(QApplication::translate("MainWindow", "DIIS Start", Q_NULLPTR));
        label_52->setText(QApplication::translate("MainWindow", "DIIS Size", Q_NULLPTR));
        label_38->setText(QApplication::translate("MainWindow", "This panel is never displayed, it \n"
"just forms a container for the \n"
"various EOM state specification \n"
"widgets.", Q_NULLPTR));
        label_33->setText(QApplication::translate("MainWindow", "First electronic state", Q_NULLPTR));
        label_73->setText(QApplication::translate("MainWindow", "Second electronic state", Q_NULLPTR));
        xopt_seam_only->setText(QApplication::translate("MainWindow", "Search for Seam Only", Q_NULLPTR));
        wavefunction_analysis->setText(QApplication::translate("MainWindow", "Wavefunction Analysis", Q_NULLPTR));
        molden_format->setText(QApplication::translate("MainWindow", "Generate MOLDEN Input", Q_NULLPTR));
        mm_charges->setText(QApplication::translate("MainWindow", "Multipole Derived Charges", Q_NULLPTR));
        hirshfeld->setText(QApplication::translate("MainWindow", "Hirshfeld populations", Q_NULLPTR));
        label_176->setText(QApplication::translate("MainWindow", "Multipole Order", Q_NULLPTR));
        label_114->setText(QApplication::translate("MainWindow", "Mulliken Populations:", Q_NULLPTR));
        label_149->setText(QApplication::translate("MainWindow", "Points", Q_NULLPTR));
        label_147->setText(QApplication::translate("MainWindow", "Property", Q_NULLPTR));
        label_148->setText(QApplication::translate("MainWindow", "Grid", Q_NULLPTR));
        skip_cis_rpa->setText(QApplication::translate("MainWindow", "Skip CIS/RPA Calculation", Q_NULLPTR));
        label_172->setText(QApplication::translate("MainWindow", "Second Order", Q_NULLPTR));
        label_171->setText(QApplication::translate("MainWindow", "First Order", Q_NULLPTR));
        label_170->setText(QApplication::translate("MainWindow", "Convergence:", Q_NULLPTR));
        label_173->setText(QApplication::translate("MainWindow", "Threshold", Q_NULLPTR));
        label_174->setText(QApplication::translate("MainWindow", "Iterations", Q_NULLPTR));
        label_79->setText(QApplication::translate("MainWindow", "Perturbation Batch Size", Q_NULLPTR));
        label_175->setText(QApplication::translate("MainWindow", "DIIS Subspace", Q_NULLPTR));
        label_44->setText(QApplication::translate("MainWindow", "Hessian Update", Q_NULLPTR));
        label_72->setText(QApplication::translate("MainWindow", "Initial Hessian", Q_NULLPTR));
        label_14->setText(QApplication::translate("MainWindow", "Coordinates", Q_NULLPTR));
        qui_geom_opt_fallback->setText(QApplication::translate("MainWindow", "Use Cartesians on Failure", Q_NULLPTR));
        label_70->setText(QApplication::translate("MainWindow", "GDIIS Subspace", Q_NULLPTR));
        label_45->setText(QApplication::translate("MainWindow", "Print Level", Q_NULLPTR));
        label_17->setText(QApplication::translate("MainWindow", "Max Cycles", Q_NULLPTR));
        geom_opt_scf_guess_always->setText(QApplication::translate("MainWindow", "Re-generate SCF Guess at Each Step", Q_NULLPTR));
        geom_print->setText(QApplication::translate("MainWindow", "Print Geometry at Each Step", Q_NULLPTR));
        geom_opt_iproj->setText(QApplication::translate("MainWindow", "Allow Moleculear Re-orientation", Q_NULLPTR));
        geom_opt_symmetry->setText(QApplication::translate("MainWindow", "Use Point Group Symmetry", Q_NULLPTR));
        label_11->setText(QApplication::translate("MainWindow", "x10<sup>-8</sup>", Q_NULLPTR));
        label_10->setText(QApplication::translate("MainWindow", "Displacement", Q_NULLPTR));
        label_113->setText(QApplication::translate("MainWindow", "x10<sup>-6</sup>", Q_NULLPTR));
        label_13->setText(QApplication::translate("MainWindow", "Gradient", Q_NULLPTR));
        label_15->setText(QApplication::translate("MainWindow", "x10<sup>-6</sup>", Q_NULLPTR));
        label_12->setText(QApplication::translate("MainWindow", "Energy", Q_NULLPTR));
        label_68->setText(QApplication::translate("MainWindow", "Linear Angle", Q_NULLPTR));
        label_71->setText(QApplication::translate("MainWindow", "Max Stepsize", Q_NULLPTR));
        geom_opt_max_step_size->setPrefix(QString());
        geom_opt_max_step_size->setSuffix(QString());
        label_56->setText(QApplication::translate("MainWindow", "Coordinates", Q_NULLPTR));
        label_58->setText(QApplication::translate("MainWindow", "Max Stepsize", Q_NULLPTR));
        label_60->setText(QApplication::translate("MainWindow", "Convergence", Q_NULLPTR));
        rpath_max_stepsize->setSuffix(QString());
        rpath_tol_displacement->setSuffix(QString());
        label_59->setText(QApplication::translate("MainWindow", "Print Level", Q_NULLPTR));
        label_103->setText(QApplication::translate("MainWindow", "Print Multipole Order", Q_NULLPTR));
        label_140->setText(QApplication::translate("MainWindow", "Number of Points", Q_NULLPTR));
        label_116->setText(QApplication::translate("MainWindow", "Fock Extrapolation Order", Q_NULLPTR));
        efp->setText(QApplication::translate("MainWindow", "EFP Calculation", Q_NULLPTR));
        efp_fragments_only->setText(QApplication::translate("MainWindow", "EFP Only Calculation (No QM)", Q_NULLPTR));
        efp_input->setText(QApplication::translate("MainWindow", "Use new EFP input format", Q_NULLPTR));
        label_110->setText(QApplication::translate("MainWindow", "Iterations", Q_NULLPTR));
        label_109->setText(QApplication::translate("MainWindow", "Threshold", Q_NULLPTR));
        label_111->setText(QApplication::translate("MainWindow", "Convergence:", Q_NULLPTR));
        label_112->setText(QApplication::translate("MainWindow", "DIIS Subspace", Q_NULLPTR));
        label_107->setText(QApplication::translate("MainWindow", "Level 1", Q_NULLPTR));
        label_108->setText(QApplication::translate("MainWindow", "Level 2", Q_NULLPTR));
        dcpscf_perturbations->setText(QApplication::translate("MainWindow", "Compute Perturbations Singly", Q_NULLPTR));
        label_150->setText(QApplication::translate("MainWindow", "Analytic Derivative Order", Q_NULLPTR));
        label_88->setText(QApplication::translate("MainWindow", "Finite Difference Stepsize", Q_NULLPTR));
        label_74->setText(QApplication::translate("MainWindow", "CPSCF Segments", Q_NULLPTR));
        label_vp->setText(QApplication::translate("MainWindow", "Print Level", Q_NULLPTR));
        label_95->setText(QApplication::translate("MainWindow", "Derivative Information:", Q_NULLPTR));
        readChargesButton->setText(QApplication::translate("MainWindow", "Read Charges", Q_NULLPTR));
        gaussian_blur->setText(QApplication::translate("MainWindow", "Use Gaussian-Blurred Charges", Q_NULLPTR));
        qmmm->setText(QApplication::translate("MainWindow", "Use QChem/CHARMM Interface", Q_NULLPTR));
        qmmm_charges->setText(QApplication::translate("MainWindow", "Print Charges", Q_NULLPTR));
        link_atom_projection->setText(QApplication::translate("MainWindow", "Perform Link-Atom Projection", Q_NULLPTR));
        qmmm_full_hessian->setText(QApplication::translate("MainWindow", "Compute Full QM/MM Hessian", Q_NULLPTR));
        label_64->setText(QApplication::translate("MainWindow", "Solvent Method", Q_NULLPTR));
        solventGroupBox->setTitle(QApplication::translate("MainWindow", "Solvent", Q_NULLPTR));
        label_b160_3->setText(QApplication::translate("MainWindow", "Dielectric", Q_NULLPTR));
        label_a160->setText(QApplication::translate("MainWindow", "Cavity Radius", Q_NULLPTR));
        label_97->setText(QApplication::translate("MainWindow", "Optical Dielectric", Q_NULLPTR));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "Options", Q_NULLPTR));
        label_37->setText(QApplication::translate("MainWindow", "Multipole Order", Q_NULLPTR));
        label_75->setText(QApplication::translate("MainWindow", "Print Level", Q_NULLPTR));
        label_80->setText(QApplication::translate("MainWindow", "Model", Q_NULLPTR));
        label_81->setText(QApplication::translate("MainWindow", "Boundary", Q_NULLPTR));
        label_96->setText(QApplication::translate("MainWindow", "Radii", Q_NULLPTR));
        label_f161->setText(QApplication::translate("MainWindow", "Memory", Q_NULLPTR));
        label_d161->setText(QApplication::translate("MainWindow", "Cavity Convergence", Q_NULLPTR));
        label_e161->setText(QApplication::translate("MainWindow", "Charge Convergence", Q_NULLPTR));
        label_c161->setText(QApplication::translate("MainWindow", "Guess", Q_NULLPTR));
        qui_svp_path->setText(QApplication::translate("MainWindow", "Run gas phase", Q_NULLPTR));
        label_162b->setText(QApplication::translate("MainWindow", "Electric Field", Q_NULLPTR));
        label_162a->setText(QApplication::translate("MainWindow", "Number of Grids", Q_NULLPTR));
        qui_chemsol_print->setText(QApplication::translate("MainWindow", "Increase Printout", Q_NULLPTR));
        label_65->setText(QApplication::translate("MainWindow", "Solvent", Q_NULLPTR));
        label_54->setText(QApplication::translate("MainWindow", "Charges", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MainWindow", "Integration Grid", Q_NULLPTR));
        label_128->setText(QApplication::translate("MainWindow", "Lebedev Grid", Q_NULLPTR));
        qui_svp_intcav->setText(QApplication::translate("MainWindow", "Use Sperical Polar Grid", Q_NULLPTR));
        label_129->setText(QApplication::translate("MainWindow", "Points: \316\270", Q_NULLPTR));
        label_130->setText(QApplication::translate("MainWindow", "\317\206", Q_NULLPTR));
        groupBox_6->setTitle(QApplication::translate("MainWindow", "Grid Transformation", Q_NULLPTR));
        label_131->setText(QApplication::translate("MainWindow", "Translation", Q_NULLPTR));
        label_134->setText(QApplication::translate("MainWindow", "\316\264X", Q_NULLPTR));
        label_135->setText(QApplication::translate("MainWindow", "\316\264Y", Q_NULLPTR));
        label_136->setText(QApplication::translate("MainWindow", "\316\264Z", Q_NULLPTR));
        label_132->setText(QApplication::translate("MainWindow", "Rotation", Q_NULLPTR));
        label_137->setText(QApplication::translate("MainWindow", "\316\270", Q_NULLPTR));
        label_138->setText(QApplication::translate("MainWindow", "\317\206", Q_NULLPTR));
        label_139->setText(QApplication::translate("MainWindow", "<html><head><meta name=\"qrichtext\" content=\"1\" /></head><body style=\" white-space: pre-wrap; font-family:Lucida Grande; font-size:13pt; font-weight:400; font-style:normal; text-decoration:none;\"><p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-style:italic;\">\317\207</span></p></body></html>", Q_NULLPTR));
        symmetry_ignore->setText(QApplication::translate("MainWindow", "Ignore Point Group Symmetry", Q_NULLPTR));
        symmetry_integral->setText(QApplication::translate("MainWindow", "Use Integral Symmetry", Q_NULLPTR));
        label_62->setText(QApplication::translate("MainWindow", "Symmetry Tolerance", Q_NULLPTR));
        label_63->setText(QApplication::translate("MainWindow", "Symmetry Decompositions:", Q_NULLPTR));
        label_26->setText(QApplication::translate("MainWindow", "AO2MO Disk", Q_NULLPTR));
        label_24->setText(QApplication::translate("MainWindow", "Total Memory", Q_NULLPTR));
        label_25->setText(QApplication::translate("MainWindow", "Static Memory", Q_NULLPTR));
        mem_static->setSuffix(QApplication::translate("MainWindow", " Mb", Q_NULLPTR));
        ao2mo_disk->setSuffix(QApplication::translate("MainWindow", " Mb", Q_NULLPTR));
        label_31->setText(QApplication::translate("MainWindow", "Max File Number", Q_NULLPTR));
        label_23->setText(QApplication::translate("MainWindow", "Integrals Buffer", Q_NULLPTR));
        integrals_buffer->setSuffix(QApplication::translate("MainWindow", " Mb", Q_NULLPTR));
        mem_total->setSuffix(QApplication::translate("MainWindow", " Mb", Q_NULLPTR));
        label_16->setText(QApplication::translate("MainWindow", "This page is inaccessible to the user\n"
"and is included as a container for \n"
"controls that are set by other rems.\n"
"Eventually this should go.", Q_NULLPTR));
        cis_guess_disk->setText(QApplication::translate("MainWindow", "CIS_GUESS_DISK", Q_NULLPTR));
        setupTabWidget->setTabText(setupTabWidget->indexOf(AdvancedTab), QApplication::translate("MainWindow", "Advanced", Q_NULLPTR));
        previewOutput->setTitle(QApplication::translate("MainWindow", "Generated Input File:", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "Server", Q_NULLPTR));
        resetButton->setText(QApplication::translate("MainWindow", "Reset", Q_NULLPTR));
        cancelButton->setText(QApplication::translate("MainWindow", "Cancel", Q_NULLPTR));
        submitButton->setText(QApplication::translate("MainWindow", "Submit", Q_NULLPTR));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUIMAINWINDOW_H
