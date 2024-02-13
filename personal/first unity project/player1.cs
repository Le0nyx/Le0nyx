using System.Collections;
using System.Collections.Generic;
using JetBrains.Annotations;
using UnityEngine;

public class Player1 : MonoBehaviour
{
    public Rigidbody2D myRidbody_Player2;
    public float VectorUp;
    public float VectorDown;
    public float moveSpeed;
    public int health;
    public Animator playerAnim;
    public Transform groundCheckTransform; // Transform representing the point to check for the ground
    public float groundCheckDistance = 0.1f; // Distance to cast the ray to check for ground
    public LayerMask groundLayer; // Specify the layer(s) for the ground

    private int block_jump;
    bool isGrounded;

    // Start is called before the first frame update
    void Start()
    {
        myRidbody_Player2 = GetComponent<Rigidbody2D>();
        myRidbody_Player2.constraints = RigidbodyConstraints2D.FreezeRotation; // Freeze rotation on all axes
    }
    // Update is called once per frame
    void Update()
    {
        if(health <= 0)
        {
            //game over
            playerAnim.SetTrigger("Death");
        }




        RaycastHit2D hit = Physics2D.Raycast(groundCheckTransform.position, Vector2.down, groundCheckDistance, groundLayer);
        // Set isGrounded based on whether the raycast hits an object on the ground layer
        isGrounded = hit.collider != null;
        // Perform actions based on whether the character is grounded or not
        if (isGrounded)
        {
            block_jump = 0;
            playerAnim.SetBool("Grounded", true);
            // Character is grounded
            Debug.Log("Character is grounded");
        }
        else
        {
            block_jump = 1;
            playerAnim.SetBool("Grounded", false);
            // Character is not grounded
            Debug.Log("Character is not grounded");
        }


        playerAnim.SetInteger("AnimState", 1);

        if (Input.GetKeyDown(KeyCode.W) == true && block_jump != 1)
        {
            playerAnim.SetTrigger("jumping");
            myRidbody_Player2.velocity = Vector2.up * VectorUp;
        }

        if (Input.GetKeyDown(KeyCode.S) == true)
        {
            myRidbody_Player2.velocity = Vector2.down * VectorDown;
        }



        // Check for left arrow key
        if (Input.GetKey(KeyCode.A))
        {
            SetFacingDirection(1);
            playerAnim.SetInteger("AnimState", 2);
            // Move the player left
            transform.Translate(Vector3.left * moveSpeed * Time.deltaTime);
        }
        // Check for right arrow key
        else if (Input.GetKey(KeyCode.D))
        {
            SetFacingDirection(-1);
            playerAnim.SetInteger("AnimState", 2);
            // Move the player right
            transform.Translate(Vector3.right * moveSpeed * Time.deltaTime);
        }


    }
    public void TakeDamage(int damage)
    {
        playerAnim.SetTrigger("Hurt");
        health -= damage;
        Debug.Log("damage taken 1");
    }
    void SetFacingDirection(int direction)
    {
        Vector3 characterScale = transform.localScale;
        characterScale.x = Mathf.Abs(characterScale.x) * direction; // Set character's scale based on direction
        transform.localScale = characterScale;
    }
}
