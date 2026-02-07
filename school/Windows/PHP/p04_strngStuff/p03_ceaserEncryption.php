<?php

$text = "hallo welt";
$shift = 3;

// Alphabet arrays
$lower = ['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'];
$upper = ['A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'];

$encrypted = "";

// Encrypt each character
for ($i = 0; $i < strlen($text); $i++) {
    $char = $text[$i];
    $found = false;
    
    // Check lowercase
    for ($j = 0; $j < count($lower); $j++) {
        if ($char === $lower[$j]) {
            $newPos = ($j + $shift) % count($lower);
            $encrypted .= $lower[$newPos];
            $found = true;
            break;
        }
    }
    
    // Check uppercase if not found
    if (!$found) {
        for ($j = 0; $j < count($upper); $j++) {
            if ($char === $upper[$j]) {
                $newPos = ($j + $shift) % count($upper);
                $encrypted .= $upper[$newPos];
                $found = true;
                break;
            }
        }
    }
    
    // Keep non-letters unchanged
    if (!$found) {
        $encrypted .= $char;
    }
}

echo "Original: " . $text . "\n";
echo "Encrypted: " . $encrypted . "\n";

// Decrypt (reverse shift)
$decrypted = "";
$shift = -3;

for ($i = 0; $i < strlen($encrypted); $i++) {
    $char = $encrypted[$i];
    $found = false;
    
    for ($j = 0; $j < count($lower); $j++) {
        if ($char === $lower[$j]) {
            $newPos = ($j + $shift + count($lower)) % count($lower);
            $decrypted .= $lower[$newPos];
            $found = true;
            break;
        }
    }
    
    if (!$found) {
        for ($j = 0; $j < count($upper); $j++) {
            if ($char === $upper[$j]) {
                $newPos = ($j + $shift + count($upper)) % count($upper);
                $decrypted .= $upper[$newPos];
                $found = true;
                break;
            }
        }
    }
    
    if (!$found) {
        $decrypted .= $char;
    }
}

echo "Decrypted: " . $decrypted . "\n";
?>
