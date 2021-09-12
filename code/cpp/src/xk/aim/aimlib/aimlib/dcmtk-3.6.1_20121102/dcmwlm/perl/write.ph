#!/usr/local/bin/perl
#
#  Copyright (C) 1996-2010, OFFIS e.V.
#  All rights reserved.  See COPYRIGHT file for details.
#
#  This software and supporting documentation were developed by
#
#    OFFIS e.V.
#    R&D Division Health
#    Escherweg 2
#    D-26121 Oldenburg, Germany
#
#  for CEN/TC251/WG4 as a contribution to the Computer Assisted Radiology
#  (CAR) 1996 DICOM Demonstration.
#
#
# Module: dcmwlm (WWW Component)
#
# Author: Marco Eichelberg
#
# Purpose:
#   This module contains perl code that writes/reads the patient,
#   procedure, procedure step and station data and creates IDs.
#
#

require 'prefs.ph';

#
# void write_environment(string filename)
#   writes these global variables to file:
#     @PATIENT_KEYS, %PATIENT_VALUES
#     @STATION_KEYS, %STATION_VALUES
#     @PROCEDURE_KEYS, %PROCEDURE_VALUES
#     @PROCEDURESTEP_KEYS, %PROCEDURESTEP_VALUES
#     $LASTPIDPOSTFIX, $LASTUIDPOSTFIX
#
sub write_environment
{
  if (@_[0] eq '') { die "filename missing in sub write_environment"; }

  if (open(outfile, ">@_[0]"))
  {
    print outfile <<EOF;
#!/usr/local/bin/perl
#
# automatically generated by write.pl - do not modify!
#

EOF

    printf(outfile "# Patient Data\n\n");
    if ($#PATIENT_KEYS<0)
    {
      printf(outfile 'undef @PATIENT_KEYS;');
      printf(outfile "\n");
      printf(outfile 'undef %%PATIENT_VALUES;');
      printf(outfile "\n\n");
    } else {
      printf(outfile '@PATIENT_KEYS = (');
      $comma = 0;
      foreach(@PATIENT_KEYS)
      {
        if($comma) { printf(outfile ",\n  "); } else { $comma=1; }
        printf(outfile "pack(\"H*\",'%s')",unpack("H*",$_));
      }
      printf(outfile ");\n\n");

      printf(outfile '%%PATIENT_VALUES = (');
      printf(outfile "\n  ");
      $comma = 0;
      foreach(@PATIENT_KEYS)
      {
        if($comma) { printf(outfile ",\n  "); } else { $comma=1; }
        printf(outfile "pack(\"H*\",'%s'), pack(\"H*\",'%s'),\n  ",unpack("H*","$_\\name"),      unpack("H*",$PATIENT_VALUES{"$_\\name"}));
        printf(outfile "pack(\"H*\",'%s'), pack(\"H*\",'%s'),\n  ",unpack("H*","$_\\birthdate"), unpack("H*",$PATIENT_VALUES{"$_\\birthdate"}));
        printf(outfile "pack(\"H*\",'%s'), pack(\"H*\",'%s'),\n  ",unpack("H*","$_\\sex"),       unpack("H*",$PATIENT_VALUES{"$_\\sex"}));
        printf(outfile "pack(\"H*\",'%s'), pack(\"H*\",'%s'),\n  ",unpack("H*","$_\\alerts"),    unpack("H*",$PATIENT_VALUES{"$_\\alerts"}));
        printf(outfile "pack(\"H*\",'%s'), pack(\"H*\",'%s')\n  " ,unpack("H*","$_\\allergies"), unpack("H*",$PATIENT_VALUES{"$_\\allergies"}));
      }
      printf(outfile ");\n\n");

    }

    printf(outfile "# Station Data\n\n");
    if ($#STATION_KEYS<0)
    {
      printf(outfile 'undef @STATION_KEYS;');
      printf(outfile "\n");
      printf(outfile 'undef %%STATION_VALUES;');
      printf(outfile "\n\n");
    } else {
      printf(outfile '@STATION_KEYS = (');
      $comma = 0;
      foreach(@STATION_KEYS)
      {
        if($comma) { printf(outfile ",\n  "); } else { $comma=1; }
        printf(outfile "pack(\"H*\",'%s')",unpack("H*",$_));
      }
      printf(outfile ");\n\n");

      printf(outfile '%%STATION_VALUES = (');
      printf(outfile "\n  ");
      $comma = 0;
      foreach(@STATION_KEYS)
      {
        if($comma) { printf(outfile ",\n  "); } else { $comma=1; }
        printf(outfile "pack(\"H*\",'%s'), pack(\"H*\",'%s'),\n  ",unpack("H*","$_\\name"),      unpack("H*",$STATION_VALUES{"$_\\name"}));
        printf(outfile "pack(\"H*\",'%s'), pack(\"H*\",'%s')\n  ", unpack("H*","$_\\modality"),  unpack("H*",$STATION_VALUES{"$_\\modality"}));
      }
      printf(outfile ");\n\n");
    }

    printf(outfile "# Procedure Data\n\n");
    if ($#PROCEDURE_KEYS<0)
    {
      printf(outfile 'undef @PROCEDURE_KEYS;');
      printf(outfile "\n");
      printf(outfile 'undef %%PROCEDURE_VALUES;');
      printf(outfile "\n\n");
    } else {
      printf(outfile '@PROCEDURE_KEYS = (');
      $comma = 0;
      foreach(@PROCEDURE_KEYS)
      {
        if($comma) { printf(outfile ",\n  "); } else { $comma=1; }
        printf(outfile "pack(\"H*\",'%s')",unpack("H*",$_));
      }
      printf(outfile ");\n\n");

      printf(outfile '%%PROCEDURE_VALUES = (');
     printf(outfile "\n  ");
      $comma = 0;
      foreach(@PROCEDURE_KEYS)
      {
        if($comma) { printf(outfile ",\n  "); } else { $comma=1; }
        printf(outfile "pack(\"H*\",'%s'), pack(\"H*\",'%s'),\n  ",unpack("H*","$_\\title"),       unpack("H*",$PROCEDURE_VALUES{"$_\\title"}));
        printf(outfile "pack(\"H*\",'%s'), pack(\"H*\",'%s'),\n  ",unpack("H*","$_\\description"), unpack("H*",$PROCEDURE_VALUES{"$_\\description"}));
        printf(outfile "pack(\"H*\",'%s'), pack(\"H*\",'%s')\n  ", unpack("H*","$_\\priority"),    unpack("H*",$PROCEDURE_VALUES{"$_\\priority"}));
      }
      printf(outfile ");\n\n");
    }

    printf(outfile "# Procedure Step Data\n\n");
    if ($#PROCEDURESTEP_KEYS<0)
    {
      printf(outfile 'undef @PROCEDURESTEP_KEYS;');
      printf(outfile "\n");
      printf(outfile 'undef %%PROCEDURESTEP_VALUES;');
      printf(outfile "\n\n");
    } else {
      printf(outfile '@PROCEDURESTEP_KEYS = (');
      $comma = 0;
      foreach(@PROCEDURESTEP_KEYS)
      {
        if($comma) { printf(outfile ",\n  "); } else { $comma=1; }
        printf(outfile "pack(\"H*\",'%s')",unpack("H*",$_));
      }
      printf(outfile ");\n\n");

      printf(outfile '%%PROCEDURESTEP_VALUES = (');
      printf(outfile "\n  ");
      $comma = 0;
      foreach(@PROCEDURESTEP_KEYS)
      {
        if($comma) { printf(outfile ",\n  "); } else { $comma=1; }
        printf(outfile "pack(\"H*\",'%s'), pack(\"H*\",'%s'),\n  ",unpack("H*","$_\\procedure"), unpack("H*",$PROCEDURESTEP_VALUES{"$_\\procedure"}));
        printf(outfile "pack(\"H*\",'%s'), pack(\"H*\",'%s'),\n  ",unpack("H*","$_\\title"),     unpack("H*",$PROCEDURESTEP_VALUES{"$_\\title"}));
        printf(outfile "pack(\"H*\",'%s'), pack(\"H*\",'%s'),\n  ",unpack("H*","$_\\modality"),  unpack("H*",$PROCEDURESTEP_VALUES{"$_\\modality"}));
        printf(outfile "pack(\"H*\",'%s'), pack(\"H*\",'%s'),\n  ",unpack("H*","$_\\medication"),unpack("H*",$PROCEDURESTEP_VALUES{"$_\\medication"}));
        printf(outfile "pack(\"H*\",'%s'), pack(\"H*\",'%s'),\n  ",unpack("H*","$_\\contrast"),  unpack("H*",$PROCEDURESTEP_VALUES{"$_\\contrast"}));
        printf(outfile "pack(\"H*\",'%s'), pack(\"H*\",'%s'),\n  ",unpack("H*","$_\\location"),  unpack("H*",$PROCEDURESTEP_VALUES{"$_\\location"}));
        printf(outfile "pack(\"H*\",'%s'), pack(\"H*\",'%s')\n  " ,unpack("H*","$_\\comments"),  unpack("H*",$PROCEDURESTEP_VALUES{"$_\\comments"}));
      }
      printf(outfile ");\n\n");
    }

    printf(outfile "# UID/PatientID Data\n\n");
    if ($LASTPIDPOSTFIX eq '')
    {
      printf(outfile 'undef $LASTPIDPOSTFIX;');
      printf(outfile "\n");
    } else {
      printf(outfile '$LASTPIDPOSTFIX = ');
      printf(outfile "%s;\n",$LASTPIDPOSTFIX);
    }
    if ($LASTUIDPOSTFIX eq '')
    {
      printf(outfile 'undef $LASTUIDPOSTFIX;');
      printf(outfile "\n\n");
    } else {
      printf(outfile '$LASTUIDPOSTFIX = ');
      printf(outfile "%s;\n\n",$LASTUIDPOSTFIX);
    }
    printf(outfile "# make sure require() is successful on this file\n");
    printf(outfile "1;\n\n");
    close(outfile);
  } else {
    &printlog("write_environment: cannot open file @_[0] for writing");
  }
}


#
# void read_environment(string filename)
#   reads a file as defined above back.
#
sub read_environment
{
  if (-e $filename)
  {
    require($filename);
  } else {
    undef @PATIENT_KEYS;
    undef %PATIENT_VALUES;
    undef @STATION_KEYS;
    undef %STATION_VALUES;
    undef @PROCEDURE_KEYS;
    undef %PROCEDURE_VALUES;
    undef @PROCEDURESTEP_KEYS;
    undef %PROCEDURESTEP_VALUES;
    undef $LASTPIDPOSTFIX;
    undef $LASTUIDPOSTFIX;
  }
}

# string nextPID(string AEtitle)
#   returns a new Patient ID string and updates $LASTPIDPOSTFIX.
sub nextPID
{
  if ($LASTPIDPOSTFIX eq '') { $LASTPIDPOSTFIX=0; }
  $LASTPIDPOSTFIX++;
  local($pid);
  $pid = sprintf("%s%08d",@_[0],$LASTPIDPOSTFIX);
  $pid;
}

# string nextAccNr(string AEtitle)
#   returns a new Accession Number string and updates $LASTPIDPOSTFIX.
sub nextAccNr
{
  if ($LASTPIDPOSTFIX eq '') { $LASTPIDPOSTFIX=0; }
  $LASTPIDPOSTFIX++;
  local($pid);
  $pid = sprintf("ACNR%s",@_[0]);
  if (length($pid)>12) { $pid = substr($pid, 0, 12); }
  $pid = sprintf("%s%04d",$pid,$LASTPIDPOSTFIX);
  $pid;
}

# string nextProcID(string AEtitle)
#   returns a new Procedure ID string and updates $LASTPIDPOSTFIX.
sub nextProcID
{
  if ($LASTPIDPOSTFIX eq '') { $LASTPIDPOSTFIX=0; }
  $LASTPIDPOSTFIX++;
  local($pid);
  $pid = sprintf("PROC%s",@_[0]);
  if (length($pid)>12) { $pid = substr($pid, 0, 12); }
  $pid = sprintf("%s%04d",$pid,$LASTPIDPOSTFIX);
  $pid;
}

# string nextStepID(string AEtitle)
#   returns a new Procedure Step ID string and updates $LASTPIDPOSTFIX.
sub nextStepID
{
  if ($LASTPIDPOSTFIX eq '') { $LASTPIDPOSTFIX=0; }
  $LASTPIDPOSTFIX++;
  local($pid);
  $pid = sprintf("PSTEP%s",@_[0]);
  if (length($pid)>12) { $pid = substr($pid, 0, 12); }
  $pid = sprintf("%s%04d",$pid,$LASTPIDPOSTFIX);
  $pid;
}

# string nextFilenamePrefix(string AEtitle)
#   returns a new filename for a DICOM file, without extension.
sub nextFilenamePrefix
{
  local($filename);
  if ($LASTPIDPOSTFIX eq '') { $LASTPIDPOSTFIX=0; }
  $LASTPIDPOSTFIX++;
  $filename = sprintf("wl%s",$LASTPIDPOSTFIX);
  $filename;
}

# string nextUID(string AEtitle)
#   returns a new UID for AEtitle.
#   We use our UID root, append the inode number of the lock file
#   for the storage area (AEtitle) and a serial number for the storage area.
sub nextUID
{
  local($uid);
  local($x);
  local($inode) = 0;
  ($x,$inode,$x,$x,$x,$x,$x,$x,$x,$x,$x,$x,$x) = stat("$prefs{'data_path'}/@_[0]/$prefs{'lockfile'}");
  if ($LASTUIDPOSTFIX eq '') { $LASTUIDPOSTFIX=0; }
  $LASTUIDPOSTFIX++;
  $uid = sprintf("%s.%d.%d", $prefs{'series_UID'}, $inode, $LASTUIDPOSTFIX);
  $uid;
}

1;
