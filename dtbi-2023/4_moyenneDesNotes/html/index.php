<?php 
  $demander_note = "Saisire une note :  (-1 pour terminer)";
  $afficher_moyenne = "La moyenne est de : ";
  $total_notes = 0;
  $somme_notes = 0.00;
  $saisie_note = 0.00;
  $resulta = 0.00;
  $noteSup10 = 0;
  $pourcSup10 = 0.00;
  do {
    echo $demander_note, "\n";
    $saisie_note = readline();
    if ($saisie_note >= 0) {
      $somme_notes = $somme_notes + $saisie_note;
      $total_notes = $total_notes + 1;
      if ($saisie_note > 10) {
        $noteSup10 = $noteSup10 + 1;
      }
    }
  } while ($saisie_note != -1);
  if ($total_notes > 0) {
    $resulta = $somme_notes / $total_notes;
    $resulta = number_format($resulta, 2);
    $pourcSup10 = ($noteSup10 / $total_notes) * 100;
    $pourcSup10 = number_format($pourcSup10, 2); 
  }
  echo $afficher_moyenne . $resulta . "\n";
  echo "Il y a " . $pourcSup10 . " % de notes au dessus de 10";
?>