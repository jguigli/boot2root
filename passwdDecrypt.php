<?php
$hashedPassword = "0171e7dbcbf4bd21a732fa859ea98a2950b4f8aa1e5365dc90";
$passwordToCheck = "!q\]Ej?*5K5cy*AJ";

$decryptedPassword = "*".strtoupper(sha1(sha1($passwordToCheck, true)));
if ($decryptedPassword === $hashedPassword) {
    echo "Mot de passe déchiffré avec succès : ".$passwordToCheck;
} else {
    echo "Le mot de passe fourni ne correspond pas.";
}
?>

