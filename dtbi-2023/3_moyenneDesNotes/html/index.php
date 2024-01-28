<?php 
  $total_notes = 3;
  $somme_notes = 0.0;
  $saisie_note = 0.0;
  $resulta = 0.0;
  $i = 1;
  for ($i = 1; $i <= $total_notes; $i++) {
    $saisie_note = readline("Saisire une note : ");
    $somme_notes = $somme_notes + $saisie_note;
  }
  $resulta = $somme_notes / $total_notes;
  echo "La moyenne est de : " . number_format($resulta, 2) . "\n";
?>