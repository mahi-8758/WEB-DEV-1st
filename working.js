// Login form handler
function handleLogin(event) {
    event.preventDefault();
    
    const username = document.getElementById('username').value;
    const password = document.getElementById('password').value;
    
    // Clear any previous error messages
    clearErrorMessage();
    
    // Check credentials and redirect accordingly
    if (username === 'mai' && password === '1234') {
        showSuccessMessage('Login successful! Redirecting to YouTube...');
        
        // Add a small delay for better user experience
        setTimeout(function() {
            window.location.href = 'https://www.youtube.com';
        }, 1500);
        
    } else if (username === 'demo' && password === 'password') {
        showSuccessMessage('Login successful! Welcome, ' + username + '!');
        // In a real application, you could redirect to a dashboard
        
    } else {
        // Show specific error message based on what went wrong
        if (username === 'mai' && password !== '1234') {
            showErrorMessage('⚠️ Wrong password for user "mai". Please try again.');
        } else if (username === 'demo' && password !== 'password') {
            showErrorMessage('⚠️ Wrong password for user "demo". Please try again.');
        } else if (username === 'mai' || username === 'demo') {
            showErrorMessage('⚠️ Wrong password. Please check your password and try again.');
        } else {
            showErrorMessage('❌ Invalid username. Available users:<br>• Username: "mai" Password: "1234" (redirects to YouTube)<br>• Username: "demo" Password: "password"');
        }
        
        // Add shake animation to form on error
        addShakeAnimation();
    }
}

// Initialize interactive effects when DOM is loaded
document.addEventListener('DOMContentLoaded', function() {
    
    // Create message container for login feedback
    createMessageContainer();
    
    // Add shake animation keyframes to the page
    addShakeKeyframes();
    
    // Add bookmark hover effects
    document.querySelectorAll('.bookmark-item').forEach(item => {
        item.addEventListener('mouseenter', function() {
            this.style.borderLeftWidth = '6px';
        });
        
        item.addEventListener('mouseleave', function() {
            this.style.borderLeftWidth = '4px';
        });
    });

    // Form input animations
    document.querySelectorAll('input').forEach(input => {
        input.addEventListener('focus', function() {
            this.parentElement.style.transform = 'scale(1.02)';
        });
        
        input.addEventListener('blur', function() {
            this.parentElement.style.transform = 'scale(1)';
        });
    });
    
    // Add smooth scroll behavior for any future internal links
    document.documentElement.style.scrollBehavior = 'smooth';
    
    // Console message for developers
    console.log('Login & Bookmarks page loaded successfully!');
    console.log('Available credentials:');
    console.log('1. Username: mai, Password: 1234 (redirects to YouTube)');
    console.log('2. Username: demo, Password: password (demo login)');
});

// Create message container for login feedback
function createMessageContainer() {
    const loginForm = document.querySelector('.login-form');
    const messageDiv = document.createElement('div');
    messageDiv.id = 'login-message';
    messageDiv.style.cssText = `
        margin-top: 15px;
        padding: 12px;
        border-radius: 8px;
        text-align: center;
        font-size: 14px;
        display: none;
        transition: all 0.3s ease;
    `;
    
    // Insert before the forgot password section
    const forgotPassword = document.querySelector('.forgot-password');
    loginForm.insertBefore(messageDiv, forgotPassword);
}

// Show success message
function showSuccessMessage(message) {
    const messageDiv = document.getElementById('login-message');
    messageDiv.innerHTML = message;
    messageDiv.style.cssText += `
        display: block;
        background: rgba(76, 175, 80, 0.2);
        color: rgba(255, 255, 255, 0.95);
        border: 1px solid rgba(76, 175, 80, 0.3);
    `;
    messageDiv.scrollIntoView({ behavior: 'smooth', block: 'nearest' });
}

// Show error message
function showErrorMessage(message) {
    const messageDiv = document.getElementById('login-message');
    messageDiv.innerHTML = message;
    messageDiv.style.cssText += `
        display: block;
        background: rgba(244, 67, 54, 0.2);
        color: rgba(255, 255, 255, 0.95);
        border: 1px solid rgba(244, 67, 54, 0.3);
    `;
    messageDiv.scrollIntoView({ behavior: 'smooth', block: 'nearest' });
}

// Clear any existing messages
function clearErrorMessage() {
    const messageDiv = document.getElementById('login-message');
    if (messageDiv) {
        messageDiv.style.display = 'none';
    }
}

// Add shake animation to form on login error
function addShakeAnimation() {
    const loginForm = document.querySelector('.login-form');
    loginForm.style.animation = 'shake 0.5s ease-in-out';
    
    // Remove animation after it completes
    setTimeout(() => {
        loginForm.style.animation = '';
    }, 500);
    
    // Also add temporary red border to inputs
    const inputs = document.querySelectorAll('input');
    inputs.forEach(input => {
        input.style.borderBottom = '2px solid rgba(244, 67, 54, 0.8)';
        setTimeout(() => {
            input.style.borderBottom = '';
        }, 2000);
    });
}

// Add shake keyframes to the page
function addShakeKeyframes() {
    const style = document.createElement('style');
    style.textContent = `
        @keyframes shake {
            0%, 100% { transform: translateX(0); }
            10%, 30%, 50%, 70%, 90% { transform: translateX(-5px); }
            20%, 40%, 60%, 80% { transform: translateX(5px); }
        }
    `;
    document.head.appendChild(style);
}